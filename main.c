#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<dirent.h>
#include<stddef.h>
#include<sys/stat.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
#include<errno.h>

void myls(char*,char**);
void myps(char **);
void pse(char **);
int cp(int,char**);
int mymv(int,char **);
int grep(char**);
int main(){
	while(1){
        char *username=getlogin();
        if(username==NULL){
                printf("Error getting username\n");
                exit(0);
        }
        char host[100];
        if(gethostname(host,100)!=0){
                printf("Error getting hostname\n");
                exit(0);
        }
        char currdir[100];
        if(getcwd(currdir,100)==NULL){
                printf("Error getting current directory\n");
                exit(0);
        }
	
        char *start=strcat(username,"@");

        start=strcat(start,host);
        start=strcat(start,":");
        start=strcat(start,currdir);
        start=strcat(start,"$ ");
        

       char *cmd;
       cmd=readline(start);
      char cmbuf[100];
               strcpy(cmbuf,cmd);
               char *argv[100];
               int i=1;
               
               
               argv[0]=strtok(cmbuf," ");
               while(1){
               argv[i]=strtok(NULL," ");
               
               if(argv[i]==NULL)break;
               i++;
               }
               

      if(strlen(cmd)>0)add_history(cmd);
      if(argv[0]==NULL)continue;
       if(system(NULL)!=0){
               if(strcmp(argv[0],"exit")==0){printf("\t\t\t\tBYEE\n");break;}
	       else if(strcmp(argv[0],"help")==0){
	       		     size_t len=0;
	                      char *line;
	                      FILE* fp=fopen("help.txt","r");
			      while(getline(&line,&len,fp)!=-1)printf("%s",line);
			}
	       else if(strcmp(argv[0],"cd")==0){
                       char dir[100];
		       if(cmd[2]=='\0')
			       chdir(getenv("HOME"));
		       else{
                       int i=3,j=1;
		       dir[0]='/';
                       while(cmd[i]!='\0'){
                               dir[j]=cmd[i];
                               i++;j++;
                       }
		       dir[j]='\0';
		       strcat(currdir,dir);
                       if(chdir(currdir)!=0)printf("error in changing directory: %i\n",errno);
               }}
	       else if(strcmp(argv[0],"myls")==0){myls(currdir,argv);}
               else if(strcmp(argv[0],"myps")==0){if(argv[1]!=NULL){if(strcmp(argv[1],"-e")==0||strcmp(argv[1],"-eF")==0)pse(argv);else myps(argv);}else myps(argv);}
	       else if(strcmp(argv[0],"mycp")==0){
		       
                if(cp(i,argv)==-1)continue;;

	       }
	       else if(strcmp(argv[0],"mymv")==0){if(mymv(i,argv)==-1)continue;}
	       else if(strcmp(argv[0],"mygrep")==0){if(grep(argv)==-1)continue;}
	       
	       else system(cmd);
       }
       else{
               printf("Error getting the shell!!\n");
               continue;
       }

}}
                                 
