#include "header.h"
int grep(char *argv[]){
if(argv[2]==NULL){
         if(strcmp(argv[1],"--help")==0){
	                      size_t len=0;
	                      char *line;
	                      FILE* fp=fopen("mygrep_help.txt","r");
			      while(getline(&line,&len,fp)!=-1)printf("%s",line);
	}}
	else{
FILE *fp;
size_t len=0;
char *line;
ssize_t read;
int cnt=0,ln=1;
if(!(strcmp(argv[1],"-s")==0||strcmp(argv[1],"-c")==0||strcmp(argv[1],"-n")==0||strcmp(argv[1],"-m")==0)){
int i=2;
while(argv[i]!=NULL){
fp=fopen(argv[i],"r");
if(fp==NULL){printf("error getting the file!\n");return -1;}
while((read=getline(&line,&len,fp))!=-1){

if(strstr(line,argv[1])!=NULL){
printf("%s: %s",argv[i],line);
}}i++;}}
else{
if(strcmp(argv[1],"-m")==0){
int i=4;
while(argv[i]!=NULL){
fp=fopen(argv[i],"r");
if(fp==NULL){printf("error getting the file!\n");return -1;}
while((read=getline(&line,&len,fp))!=-1){

if(strstr(line,argv[3])!=NULL){
printf("%s: %s",argv[i],line);cnt++;
}if(cnt==atoi(argv[2]))break;
}if(cnt==atoi(argv[2]))break;i++;}}

else{ 

if(strcmp(argv[1],"-s")==0){
int i=3;
while(argv[i]!=NULL){
fp=fopen(argv[i],"r");
if(fp==NULL)return -1;
while((read=getline(&line,&len,fp))!=-1){

if(strstr(line,argv[1])!=NULL){
printf("%s: %s",argv[i],line);
}}i++;}}


else{
int i=3;
while(argv[i]!=NULL){
int l=1,cnt=0;
fp=fopen(argv[i],"r");
if(fp==NULL){printf("error getting the file!\n");return -1;}
while((read=getline(&line,&len,fp))!=-1){

if(strstr(line,argv[2])!=NULL){
if(strcmp(argv[1],"-c")){
printf("%s: %d: %s",argv[i],l,line);l++;
}cnt++;}}
if(strcmp(argv[1],"-c")==0)printf("%s: %d\n",argv[i],cnt);
i++;}


fclose(fp);}}}
if(line)free(line);}
return 0;
}
