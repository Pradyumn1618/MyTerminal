#include "header.h"
#include<fcntl.h>
int move(char* source,char* target){
FILE* src=fopen(source,"rb");
FILE* tar=fopen(target,"wb");
if(src==NULL||tar==NULL){printf("failed\n");return -1;}
int ch;
while((ch=fgetc(src))!=EOF){
fputc(ch,tar);
}
chmod(target,0777);
unlink(source);
fclose(src);
fclose(tar);
}
int mymv(int i,char *argv[]){
        if(argv[2]==NULL){
         if(strcmp(argv[1],"--help")==0){
	                      size_t len=0;
	                      char *line;
	                      FILE* fp=fopen("mymv_help.txt","r");
			      while(getline(&line,&len,fp)!=-1)printf("%s",line);
	}}
	else{
        struct stat source,target;
        int s,t;
        if(argv[3]!=NULL&&(strcmp(argv[1],"-i")==0||strcmp(argv[1],"-u")==0||strcmp(argv[1],"-n")==0||strcmp(argv[1],"-v")==0)){
        if(strcmp(argv[1],"-i")==0){
        printf("mymv: overwrite '%s'?\n",argv[3]);
        char c;
        scanf(" %c",&c);
        
        if(c!='y'&&c!='Y'){printf("you denied to overwrite!\n");return -1;}
        }
        else if(strcmp(argv[1],"-n")==0){
        if(access(argv[3],F_OK)!=-1){printf("target file exits,can't overwrite\n");return -1;}
        }
        else if(strcmp(argv[1],"-u")==0){
        if(stat(argv[2],&source)==-1){printf("error getting source file\n");return -1;}
        
       
       if(stat(argv[3],&target)!=-1){
         if(source.st_mtime<=target.st_mtime){printf("source is not newer than target\n");return -1;}}
         }
         
         
         if(strcmp(argv[1],"-v")==0)printf("renamed '%s' -> '%s'\n",argv[2],argv[3]);
         
	s =open(argv[2],O_RDONLY);
	if(s==-1){printf("error getting source file\n");return -1;}
	char temp[100];
        char buff[100];
        strcpy(buff,argv[2]);
        char *token=strtok(buff,"/");
        while(token!=NULL){
        strcpy(temp,token);
        token=strtok(NULL,"/");
        }
	if(access(argv[3],F_OK)!=-1){
	stat(argv[3],&target);
        if(S_ISREG(target.st_mode)==0)sprintf(argv[3],"%s/%s",argv[3],temp);}
	t=open(argv[3],O_WRONLY|O_CREAT|O_TRUNC,0777);
	if(t==-1){printf("error\n");return -1;}
	char buf[1024];
	ssize_t read_buf;
       
	while((read_buf=read(s,buf,sizeof(buf)))>0){
		ssize_t write_buf=write(t,buf,read_buf);
	}
	close(s);
	close(t);
	unlink(argv[2]);
	}
	else if(argv[3]==NULL){
	     s =open(argv[1],O_RDONLY);
	if(s==-1){printf("error getting source file\n");return -1;}
	char temp[100];
        char buff[100];
        strcpy(buff,argv[1]);
        char *token=strtok(buff,"/");
        while(token!=NULL){
        strcpy(temp,token);
        token=strtok(NULL,"/");
        }
	if(access(argv[2],F_OK)!=-1){
	stat(argv[2],&target);
        if(S_ISREG(target.st_mode)==0)sprintf(argv[2],"%s/%s",argv[2],temp);}
	   t=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0777);
	if(t==-1){printf("error\n");return -1;}
	
	
	char buf[1024];
	ssize_t read_buf;
       
	while((read_buf=read(s,buf,sizeof(buf)))>0){
		ssize_t write_buf=write(t,buf,read_buf);
	}
	close(s);
	close(t);
	unlink(argv[1]);}
	else if(argv[3]!=NULL&&!(strcmp(argv[1],"-i")==0||strcmp(argv[1],"-u")==0||strcmp(argv[1],"-n")==0||strcmp(argv[1],"-v")==0)){
	for(int j=1;j<i-1;j++){
	stat(argv[i-1],&target);
        if(S_ISREG(target.st_mode)!=0){printf("The given target is not a directory!\n");return -1;}
	char dest[250];
        char temp[100];
        char buff[100];
        strcpy(buff,argv[j]);
        char *token=strtok(buff,"/");
        while(token!=NULL){
        strcpy(temp,token);
        token=strtok(NULL,"/");
        }
        
        snprintf(dest,sizeof(dest),"%s/%s",argv[i-1],temp);
        if(move(argv[j],dest)==-1)return -1;
        }}
	printf("moved!\n");}
	return 0;
}
