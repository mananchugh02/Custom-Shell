#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    char * token = argv[0];
    if(strcmp(token , "./LS_code")==0){
        token = argv[1];
    }
    if(strcmp(token , "s")==0 || strlen(token)==0){
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if(d){
            while((dir = readdir(d))!=NULL){
                if(dir->d_name[0] != '.'){
                    printf("%s ", dir->d_name);
                }
            }
            printf("\n");   
            closedir(d);
        }
    }
    else if(strcmp(token , "-r") == 0){
        struct dirent **dir;
		int n=scandir("." , &dir , 0 , alphasort);
		int i=n-1;
		while(i>=0){
			if(dir[i]->d_name[0]!='.'){
				printf("%s ",dir[i]->d_name);
				free(dir[i]);    
			}
			i--;
		}
		free(dir);
		printf("\n");
    }
    else if(strcmp(token , "-a") == 0){
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if(d){
            while((dir = readdir(d))!=NULL){
                printf("%s ", dir->d_name);
            }
            printf("\n");
            closedir(d);
        }
    }
    else if(strlen(token)!=0 && token[0]!='-'){
        DIR *d;
        struct dirent *dir;
        d = opendir(token);
        if(d){
            while((dir = readdir(d))!=NULL){
                if(dir->d_name[0] != '.'){
                    printf("%s ", dir->d_name);
                }
            }
            printf("\n");
            closedir(d);
        }
        else{
            printf("Directory %s doesnot exist\n",token);
        }
    }
    else{
        printf("Invalid Command\n");
    }
    return 0;
}