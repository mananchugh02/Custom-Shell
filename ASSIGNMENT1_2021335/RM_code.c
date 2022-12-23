#include <stdio.h>
#include <string.h>

int main(int argc , char *argv[]){
    char *token = argv[0];
    char *rest = argv[1];
    if(token == NULL){
        printf("Invalid Command");
    }
    else if(strcmp(token , "-f") == 0){
        char* f_name = strtok(rest , " ");
        if(strcmp(f_name , "rm")==0){
            f_name = strtok(NULL," ");
            if(strcmp(f_name , "-f")==0){
                f_name = strtok(NULL,"\n"); 
            }
        }
        int a = remove(f_name);
        f_name = strtok(NULL," ");
    }

    else if(strcmp(token , "-i") == 0){
        char* f_name = strtok(rest , " ");
        if(strcmp(f_name , "rm")==0){
            f_name = strtok(NULL," ");
            if(strcmp(f_name , "-i")==0){
                f_name = strtok(NULL,"\n"); 
            }
        }

        if(f_name != NULL){
            printf("Do you want to remove the file (Yes -> 1 , No -> 2) : ");
            int inp;
            scanf("%d",&inp);
            if(inp == 1){
                int a = remove(f_name);
                if(a!= 0){
                    printf("File %s does not exist. \n",f_name);
                }
            }
            else{
                return 0;
            }
        }
        else{
            printf("Invalid Command\n");
        }
    }
    else{
        char* f_name = strtok(rest , " ");
        if(strcmp(f_name , "rm")==0){
            f_name = strtok(NULL,"\n");
        }

        if(f_name != NULL){
            int a = remove(f_name);
            if(a!= 0){
                printf("File %s does not exist. \n",f_name);   
            }
        }
        else{
            printf("Invalid Command\n");
        }
    }
    return 0;
}