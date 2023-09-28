#include "header.h"
struct process{
	char com[100];
        long id;
	char t[20];
        char stime[10];
        unsigned int ppid;
        unsigned int psr;
        unsigned long sz,rss,c,startime;
        char time[10];
        char user[100];
};
void pse(char* argv[]){

	struct process *arr=(struct process*)malloc(10000*sizeof(struct process));
	DIR *dir;
	struct dirent *entry;
	struct tm *tminfo;
	
	dir=opendir("/proc");
	long i=0;
	
	

	while((entry=readdir(dir))!=NULL){
		if(isdigit(*entry->d_name)){
			struct stat filestat;
			struct passwd *pw=(struct passwd*)malloc(sizeof(struct passwd));
		char* pid=entry->d_name;
		int user;
               
		char file[100];
		sprintf(file,"/proc/%ld/stat",atol(pid));
		
		char path[100];
		sprintf(path,"/proc/%ld/fd/0",atol(pid));
		
                
                
		FILE* stat;
                stat=fopen(file,"r");
		
		
	        
		char cmd[100];
		unsigned int p,ppid,psr;
                unsigned long sz, rss,utime,stime,c;
                unsigned long long starttime;
                char state;
                char tty[20];
		fscanf(stat,"%u %s %c %u %*u %*u %*u %*u %*s %*s %*s %*s %*s %lu %lu %*s%*s%*s%*s%*s%*s%llu%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%u%lu" ,
                       &p, cmd, &state, &ppid, &utime, &stime,&starttime,&psr,&c);
                
                fclose(stat);
                char file2[100];
               sprintf(file2,"/proc/%u/statm",p);
               FILE* statm=fopen(file2,"r");
                fscanf(statm,"%lu %lu",&sz,&rss);
                fclose(statm);
                statm=fopen("/proc/uptime","r");
                double uptime;
                fscanf(statm,"%lf",&uptime);
                fclose(statm);
               
                sprintf(file2,"/proc/%ld/status",atol(pid));
                statm=fopen(file2,"r");
                int d;
                char line[250];
                while(fgets(line,sizeof(line),statm)){
                if(strncmp(line,"Uid:",4)==0){
                sscanf(line,"Uid:\t%d",&user);
                break;
                }}
               
                pw=getpwuid(user);
               
                char* u=pw->pw_name;
                strcpy(arr[i].user,u);
                
                fclose(statm);
                int fd=open(path,O_RDONLY);
                sprintf(tty,"%s",ttyname(fd));
                
                if(strcmp(tty,"(null)")==0){strcpy(tty,"abcde?");for(int i=6;i<9;i++)tty[i]=' ';tty[9]='\0';}
                
                

		strcpy(arr[i].com,cmd);
		
                int tim =(int)(float)(stime+utime)/sysconf(_SC_CLK_TCK);
                sprintf(arr[i].time,"%02d:%02d:%02d",(tim/3600)%3600,(tim/60)%60,tim%60);
                
		time_t st=time(NULL)-((double)uptime-((double)starttime/sysconf(_SC_CLK_TCK)));
		tminfo=localtime(&st);
		char timet[10];
		strftime(timet,10,"%H:%M",tminfo);
		strcpy(arr[i].stime,timet);
		strcpy(arr[i].t,tty);
		arr[i].id=p;
		arr[i].ppid=ppid;
		arr[i].psr=psr;
		arr[i].sz=sz;
		arr[i].rss=rss;
		arr[i].c=c;
		i++;
		if(i==10000)break;}}
		closedir(dir);
	   if(strcmp(argv[1],"-eF")==0){
	printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-15s%-10s%-10s\n","UID","PID","PPID","c","SZ","RSS","PSR","STIME","TTY","TIME","CMD");
	for(long k=0;k<i;k++)printf("%-10s%-10ld%-10u%-10lu%-10lu%-10lu%-10u%-10s%-15s%-10s%-10s\n",arr[k].user,arr[k].id,arr[k].ppid,arr[k].c,arr[k].sz,arr[k].rss,arr[k].psr,arr[k].stime,arr[k].t+5,arr[k].time,arr[k].com);
	free(arr);
	}
	else if(strcmp(argv[1],"-e")==0){
	printf("%s\t %s\t\t  %s\t\t %s\n","PID","TTY","TIME","CMD");
		  for(long k=0;k<i;k++)
		  printf("%ld\t %-10s\t  %-10s\t %-10s\n",arr[k].id,arr[k].t+5,arr[k].time,arr[k].com);
		  free(arr);
		  }
}

