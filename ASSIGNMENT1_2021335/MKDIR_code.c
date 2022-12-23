#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
char curr_dir[1000];

int main(int argc , char * argv[]){
    char *token = argv[0];
    char *rest = argv[1];
    getcwd(curr_dir,1000);
    if(curr_dir == NULL){
        printf("Directory doesnot exists\n");
    }
    if(token == NULL){
        printf("Invalid command mkdir");
    }
    else if(strcmp(token , "-v")==0){
        char* f_name = strtok(rest , " ");
        if(strcmp(f_name , "mkdir") == 0){
            f_name= strtok(NULL , " ");
            if(strcmp(f_name , "-v") == 0){
                f_name = strtok(NULL,"\n");
            }
        }
        getcwd(curr_dir,1000);
        while(f_name != NULL){
            char file_name[1000];
            int x = mkdir(f_name , 0777);
            if(x==-1){
                printf("cannot create %s directory, it already exist\n",f_name);
            }
            else{
                printf("directory created\n");
            }
            f_name = strtok(NULL , " ");
        }
    }
    else if(token[0]=='-' && token[1]=='m'){
        if(token[2] == '='){
            char mod[5] = "";
            char * flag = strtok(token , " ");
            for(int i=3; i<7 && token[i]!='\0'; i++){
                mod[i-3] = token[i];
            }
            char*f_name = strtok(rest , " ");
            f_name = strtok(NULL , " ");
            f_name = strtok(NULL , "\n");
            
            if(strcmp(mod , "0400")==0){
                char file_name[1000];
                int x = mkdir(f_name , 0400);
                if(x==-1){
                    printf("cannot create %s directory, it already exist\n",f_name);
                }
            }
            else if(strcmp(mod , "0777")==0){
                char file_name[1000];
                 
                int x = mkdir(f_name , 0777);
                if(x==-1){
                    printf("cannot create %s directory, it already exist\n",f_name);
                }
                else{
                    printf("created!!\n");
                }
            } 
            else if(strcmp(mod , "0100")==0){
                char file_name[1000];
                int x = mkdir(f_name , 0100);
                if(x==-1){
                    printf("cannot create %s directory, it already exist\n",f_name);
                }
            }
            else if(strcmp(mod , "0200")==0){
                char file_name[1000];
                int x = mkdir(f_name , 0200);
                if(x==-1){
                    printf("cannot create %s directory, it already exist\n",f_name);
                }
            }
            else{
                printf("unrecognized mode\n");
                return 0;
            }
        }
        else{
            printf("Invalid Command\n");
        }
    }
    else{
        char* f_name = strtok(rest , " ");
        if(strcmp(f_name , "mkdir") == 0){
            f_name= strtok(NULL , "\n");
        }
        getcwd(curr_dir,1000);
        while(f_name != NULL){;
            int x = mkdir(f_name , 0777);
            if(x==-1){
                printf("cannot create %s directory, it already exist\n",f_name);
            }
            f_name = strtok(NULL , " ");
        }
    }
    return 0;
}