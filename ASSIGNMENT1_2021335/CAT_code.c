#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
char currdir[1000];

int main(int argc , char *argv[]){
    char *token = argv[0];
    char *rest = argv[1];
    if(strcmp(token , "at")==0){
        printf("Invalid Command\n");
    }
    else if(strcmp(token , "-n")==0){
        struct stat flag;
        char* f_name=strtok(rest , " ");
		if(strcmp(f_name, "cat") == 0){
			f_name=strtok(NULL," ");
			if(strcmp(f_name , "-n") == 0){
				f_name=strtok(NULL , "\n");
			}
		}
        getcwd(currdir,1000);
        if(currdir == NULL){
            printf("Directory does not exists\n");
        }
        strcat(currdir,"/");
        strcat(currdir,f_name);
        if(stat(currdir , &flag) == -1){
			printf("File does not exist\n");
		}
        FILE * file;
        file = fopen(currdir , "r");
        if(file == NULL){
            printf("Could not open file, SORRY!!!\n");
        }
        else{
            int i=1;
            char c[1000];
            while((fgets(c,sizeof(c),file))){
                printf("%d %s\n",i,c);
                i++;
            }
        }
        fclose(file);
    }
    else if(strcmp(token , "-E")==0){
        struct stat flag;
        char* f_name=strtok(rest , " ");
		if(strcmp(f_name, "cat") == 0){
			f_name=strtok(NULL," ");
			if(strcmp(f_name , "-E") == 0){
				f_name=strtok(NULL , "\n");
			}
		}
        getcwd(currdir,1000);
        if(currdir == NULL){
            printf("Directory does not exists\n");
        }
        strcat(currdir,"/");
        strcat(currdir,f_name);
        puts(f_name);
        if(stat(currdir , &flag) == -1){
			printf("File does not exist\n");
		}
        FILE * file;
        file = fopen(currdir , "r");
        if(file == NULL){
            printf("Could not open file, SORRY!!!\n");
        }
        else{
            int i=1;
            char c[1000];
            while((fgets(c,sizeof(c),file))){
                if (c[strlen(c)-1] == '\n')
                {
                    c[strlen(c)-1] = ' ';
                }
                
                printf("%s$\n",c);
                i++;
            }
        }
        fclose(file);
    }
    else{
        struct stat flag = {0};
        FILE * file;
        getcwd(currdir,1000);
        char* f_name=strtok(rest , " ");
        if(strcmp(f_name, "cat") == 0){
			f_name=strtok(NULL,"\n");
		}
        if(currdir == NULL){
            printf("Directory does not exists\n");
        }
        strcat(currdir,"/");
        strcat(currdir,f_name);
        if(stat(currdir , &flag) == -1){
			printf("File does not exist\n");
		}
        file = fopen(f_name , "r");
        if(file == NULL){
            printf("Could not open file, SORRY!!!\n");
        }
        char c;
        while(!feof(file)){
            c = fgetc(file);
            printf("%c",c);
        }
        printf("\n");
        fclose(file);
    }
    return 0;
}