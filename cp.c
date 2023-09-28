#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<errno.h>
#include<fcntl.h>
#include "header.h"
int copy(char* source,char* target){
struct stat s;
FILE* src=fopen(source,"rb");
FILE* tar=fopen(target,"wb");
if(src==NULL||tar==NULL){printf("failed\n");return -1;}
int ch;
while((ch=fgetc(src))!=EOF){
fputc(ch,tar);
}
stat(source,&s);
chmod(target,s.st_mode);
fclose(src);
fclose(tar);
}
int cp(int i,char* argv[]){
        if(argv[2]==NULL){
         if(strcmp(argv[1],"--help")==0){
	                      size_t len=0;
	                      char *line;
	                      FILE* fp=fopen("mycp_help.txt","r");
			      while(getline(&line,&len,fp)!=-1)printf("%s",line);
	}}
	else{
        struct stat source,target;
        FILE *f1,*f2;
        
        int ch;
        if(argv[3]!=NULL&&(strcmp(argv[1],"-i")==0||strcmp(argv[1],"-u")==0||strcmp(argv[1],"-n")==0||strcmp(argv[1],"-v")==0)){
        if(strcmp(argv[1],"-i")==0){
        printf("cp: overwrite '%s'?\n",argv[3]);
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
         
         
        else if(strcmp(argv[1],"-v")==0)printf("'%s' -> '%s'\n",argv[2],argv[3]);
        f1 =fopen(argv[2],"rb");
        if(f1==NULL){printf("error in opening the source file\n");return -1;}
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

        f2 = fopen(argv[3],"wb");
        if(f2==NULL){printf("error in opening the target file\n");return -1;}
        while((ch=fgetc(f1))!=EOF){
                if(fputc(ch,f2)==EOF)printf("error\n");
        }
        stat(argv[2],&source);
        chmod(argv[3],source.st_mode);
        if(fclose(f1)!=0||fclose(f2)!=0){
                printf("error3\n");
        }
        }
        
        else if(argv[3]==NULL){
        f1 =fopen(argv[1],"rb");
        if(f1==NULL){printf("error in opening the source file\n");return -1;}
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
        
        f2 = fopen(argv[2],"wb");
        if(f2==NULL){printf("error in opening the target file\n");return -1;}
        while((ch=fgetc(f1))!=EOF){
                if(fputc(ch,f2)==EOF)printf("error\n");
        }
        stat(argv[1],&source);
        chmod(argv[2],source.st_mode);
        if(fclose(f1)!=0||fclose(f2)!=0){
                printf("error3\n");
        }}
        
        else{
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
        
        
        if(copy(argv[j],dest)==-1)return -1;
        }
        }
        printf("copied!\n");}
        return 0;
}

