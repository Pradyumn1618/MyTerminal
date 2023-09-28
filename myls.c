#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <stddef.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <ctype.h>

struct list
{
	int block;
	char per[11];
	int link;
	char *owner;
	char *grp;
	long int size;
	char date[100];
	char filename[100];
};
char *lower(char *s)
{
	for (int i = 0; i < strlen(s); i++)
		if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
	return s;
}
void myls(char argv[], char *arg[])
{
	DIR *dir;
	struct dirent *mydir;
	struct stat mystat;
	struct tm *time;
	struct passwd *own;
	struct group *group;

	dir = opendir(argv);
	struct list arr[1000];
	int s;

	if (dir == NULL)
		printf("Error in opening the direectory\n");

	if (arg[1] != NULL)
	{

		if (strcmp(arg[1], "-a") == 0)
		{
			while ((mydir = readdir(dir)) != NULL)
			{
				printf("%s   ", mydir->d_name);
			}
			printf("\n");
			return;
		}
	}

	int i = 0;
	while ((mydir = readdir(dir)) != NULL)
	{
		if (mydir->d_name[0] != '.')
		{
			stat(mydir->d_name, &mystat);
			char p[11];

			if (S_ISDIR(mystat.st_mode))
				p[0] = 'd';
			else
				p[0] = '-';
			p[1] = (mystat.st_mode & S_IRUSR) ? 'r' : '-';
			p[2] = (mystat.st_mode & S_IWUSR) ? 'w' : '-';
			p[3] = (mystat.st_mode & S_IXUSR) ? 'x' : '-';
			p[4] = (mystat.st_mode & S_IRGRP) ? 'r' : '-';
			p[5] = (mystat.st_mode & S_IWGRP) ? 'w' : '-';
			p[6] = (mystat.st_mode & S_IXGRP) ? 'r' : '-';
			p[7] = (mystat.st_mode & S_IROTH) ? 'r' : '-';
			p[8] = (mystat.st_mode & S_IWOTH) ? 'w' : '-';
			p[9] = (mystat.st_mode & S_IXOTH) ? 'x' : '-';
			p[10] = '\0';
			strcpy(arr[i].per, p);

			arr[i].link = (int)mystat.st_nlink;

			own = getpwuid(mystat.st_uid);
			arr[i].owner = own->pw_name;

			group = getgrgid(mystat.st_gid);
			arr[i].grp = group->gr_name;

			arr[i].size = mystat.st_size;
			char *temp = mydir->d_name;
			strcpy(arr[i].filename, temp);
			time = localtime(&mystat.st_mtime);
			char timet[100];
			strftime(timet, 100, " %b %d %H:%M", time);

			strcpy(arr[i].date, timet);

			i++;
		}
	}
	s = i;

	for (int j = 0; j < s - 1; j++)
	{
		for (int k = 0; k < s - 1; k++)
		{
			char temp1[100], temp2[100];
			strcpy(temp1, arr[k].filename);
			strcpy(temp2, arr[k + 1].filename);
			char *t1 = lower(temp1);
			char *t2 = lower(temp2);
			strcpy(temp1, t1);
			strcpy(temp2, t2);
			if (strcmp(temp1, temp2) > 0)
			{
				struct list temp;
				temp = arr[k + 1];
				arr[k + 1] = arr[k];
				arr[k] = temp;
			}
		}
	}

	long sum = 0;
	for (int i = 0; i < s; i++)
	{
		if (arr[i].size % 4096 == 0)
		{
			sum += ((arr[i].size) / 4096) * 4, arr[i].block = ((arr[i].size) / 4096) * 4;
		}
		else
		{
			sum += (((arr[i].size) / 4096) + 1) * 4;
			arr[i].block = (((arr[i].size) / 4096) + 1) * 4;
		}
	}

	if (arg[1] == NULL)
	{
		for (int j = 0; j < s; j++)
			printf("%s  ", arr[j].filename);
		printf("\n");
	}

	else if (strcmp(arg[1], "-l") == 0)
	{
		printf("%s %ld\n", "total", sum);

		for (int j = 0; j < i; j++)
		{

			printf("%s ", arr[j].per);
			printf("%d ", arr[j].link);
			printf("%s ", arr[j].owner);
			printf("%s ", arr[j].grp);
			printf("%ld\t", arr[j].size);
			printf("%s ", arr[j].date);
			printf("%s ", arr[j].filename);
			printf("\n");
		}
	}

	else if (strcmp(arg[1], "-lS") == 0)
	{
		for (int i = 0; i < s - 1; i++)
		{
			for (int j = 0; j < s - 1; j++)
			{
				if (arr[j].size < arr[j + 1].size)
				{
					struct list temp;
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		printf("%s %ld\n", "total", sum);

		for (int j = 0; j < s; j++)
		{

			printf("%s ", arr[j].per);
			printf("%d ", arr[j].link);
			printf("%s ", arr[j].owner);
			printf("%s ", arr[j].grp);
			printf("%ld\t", arr[j].size);
			printf("%s ", arr[j].date);
			printf("%s ", arr[j].filename);
			printf("\n");
		}
	}
	else if (strcmp(arg[1], "-s") == 0)
	{

		printf("total %ld\n", sum);
		for (int i = 0; i < s; i++)
		{
			if (arr[i].size % 4096 == 0)
			{
				printf("%ld %s  ", ((arr[i].size) / 4096) * 4, arr[i].filename);
			}
			else
				printf("%ld %s  ", (((arr[i].size) / 4096) + 1) * 4, arr[i].filename);
		}
		printf("\n");
	}
	else if (strcmp(arg[1], "-g") == 0)
	{
		printf("%s %ld\n", "total", sum);

		for (int j = 0; j < i; j++)
		{

			printf("%s ", arr[j].per);
			printf("%d ", arr[j].link);

			printf("%s ", arr[j].grp);
			printf("%ld\t", arr[j].size);
			printf("%s ", arr[j].date);
			printf("%s ", arr[j].filename);
			printf("\n");
		}
	}
	else if (strcmp(arg[1], "-ls") == 0)
	{
		printf("%s %ld\n", "total", sum);

		for (int j = 0; j < i; j++)
		{
			printf("%6d ", arr[j].block);
			printf("%s ", arr[j].per);
			printf("%d ", arr[j].link);
			printf("%s ", arr[j].owner);
			printf("%s ", arr[j].grp);
			printf("%ld\t", arr[j].size);
			printf("%s ", arr[j].date);
			printf("%s ", arr[j].filename);
			printf("\n");
		}
	}
	else if (strcmp(arg[1], "--help") == 0)
	{
		size_t len = 0;
		char *line;
		FILE *fp = fopen("myls_help.txt", "r");
		while (getline(&line, &len, fp) != -1)
			printf("%s", line);
	}
	else
		printf("invalid command!\n");

	closedir(dir);
}
