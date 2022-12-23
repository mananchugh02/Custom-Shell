#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
char prev[1000];
char curr[1000];

void* threadCat(void* arg ){
    char * token;
    char * inp = (char *) arg;
    token = strtok(inp , " ");
    if(strcmp(token , "ls") == 0){
        token = strtok(NULL , " ");
        char final[200] ="";
        strcat(final , "./LS_code ");
        if(token == NULL){
            strcat(final , "s");
        }
        else{
            strcat(final , token);
        }
        system(final);
    }
    else if(strcmp(token , "date") == 0){
        token = strtok(NULL , " ");
        char final[200] ="";
        strcat(final , "./DATE_code ");
        if(token == NULL){
            strcat(final , "ate");
        }
        else{
            strcat(final , token);
        }
        system(final);
    }
    
}
void change_dir(char* arg){
    int x = chdir(arg);
    if(x==-1){
		printf("Error in changing directory to %s\n",arg);
	}
	else{
		strcpy(prev , curr);
		getcwd(curr,1000);
	}
}
void cd(char loc[]){
    if(strcmp(loc , "d")==0 || strcmp(loc , "-")==0){
        change_dir(prev);
    }
    else if(strcmp(loc , "~")==0){
        change_dir(getenv("HOME"));
    }
    else if(loc[0]=='-'){
        char *token = strtok(loc , " ");
        if(strcmp(token , "-L") || strcmp(token , "-P")){
            token = strtok(NULL , " ");
            if(token == NULL){
                change_dir(getenv("HOME"));
            }
            else{
                change_dir(token);
            }
        }
    }
    else{
        change_dir(loc);
    }
}
void echo(char args[]){
    if((args[0]=='"' && args[strlen(args)-1]=='"') || (args[0]=='\'' && args[strlen(args)-1]=='\'')){
        for(int i=1; i<strlen(args)-1; i++){
            printf("%c",args[i]);
        }
        printf("\n");
    }
    else if(args[0]=='-'){
        char *token = strtok(args , " ");
        if(strcmp(token , "-n")==0){
            token = strtok(NULL , " ");
            printf("%s", token);  
        }
        else if(strcmp(token , "-E")==0){
            token = strtok(NULL , " ");
            printf("%s\n", token); 
        }
    }
    else{
        printf("%s\n", args); 
    }
}
void pwd(char args[]){
    if(strcmp(args , "wd")==0 || strcmp(args , "-L")==0 || strcmp(args , "-P")==0 || strlen(args)==0){
        printf("%s\n",getcwd(curr,100));
    }
    else{
        printf("Invalid command\n" );
    }
}
void Exit(){
    exit(0);
}
int main(int argc , char* argv[]){
    printf("Welcome to MANAN's SHELL\n");
    while(1){
        char command[100] = "";
        char inp[110] = "";
        char function[6] = "";
        char rest[100] = "";
        char inp1[101] = "";

        int idx;
        getcwd(curr,100);
        getcwd(prev,100);
        printf("[%s]$ ", curr);
        // printf("Enter the command\n");
        fgets(command,100,stdin);
        strcat(inp , command);
        strcat(inp, " ");
        for(int i=0; i<strlen(command)-1; i++){
            if(command[i]==' '){
                idx = i;
                break;
            }
            else{
                function[i] = command[i];
            }
        }
        if(strcmp(function , "exit")== 0){
            Exit();
        }
        for(int j = idx+1; j<strlen(command)-1; j++){
            rest[j-idx-1] = command[j];
        }
        strcat(inp1 , rest);
        char* token = strtok(rest , " ");
        if(token!=NULL && strcmp(token , "&t") == 0){
            token = strtok(NULL , " ");
            // puts(token);
            while(token!=NULL){
                strcat(function , " ");
                strcat(function , token);
                token = strtok(NULL , " ");
                // puts(function);
            }
            pthread_t tid;
            pthread_create(&tid , NULL , threadCat , function);
            pthread_join(tid , NULL);
        }
        else if(strcmp(function , "cd")==0){
            cd(inp1);
        }
        else if(strcmp(function , "echo")==0){
            echo(inp1);
        }
        else if(strcmp(function , "pwd")==0){
            pwd(inp1);
        }
        else if(strcmp(function , "ls")==0){
            pid_t pid = fork();
            if(pid < 0){
                printf("Error in forking");
            }
            else if(pid == 0){
                char *token = strtok(rest, " ");
                execl("./LS_code" , token , NULL);
                exit(0);
            }
            else if(pid > 0){
                waitpid(0,NULL,0);
            }
        }
        else if(strcmp(function , "cat")==0){
            pid_t pid = fork();
            if(pid < 0){
                printf("Error in forking");
            }
            else if(pid == 0){
                char *token = strtok(rest, " ");
                execl("./CAT_code" , token , inp , NULL);
                exit(0);
            }
            else if(pid > 0){
                waitpid(0,NULL,0);
            }
        }
        else if(strcmp(function , "date")==0){
            pid_t pid = fork();
            if(pid < 0){
                printf("Error in forking");
            }
            else if(pid == 0){
                char *token = strtok(rest, " ");
                execl("./DATE_code" , token , NULL);
                exit(0);
            }
            else if(pid > 0){
                waitpid(0,NULL,0);
            }
        }
        else if(strcmp(function , "rm")==0){
            pid_t pid = fork();
            if(pid < 0){
                printf("Error in forking");
            }
            else if(pid == 0){
                char *token = strtok(rest, " ");
                execl("./RM_code" , token , inp , NULL);
                exit(0);
            }
            else if(pid > 0){
                waitpid(0,NULL,0);
            }
        }
        else if(strcmp(function , "mkdir")==0){
            pid_t pid = fork();
            if(pid < 0){
                printf("Error in forking");
            }
            else if(pid == 0){
                char *token = strtok(rest, " ");
                execl("./MKDIR_code" , token , inp , NULL);
                exit(0);
            }
            else if(pid > 0){
                waitpid(0,NULL,0);
            }
        }
        else{
            printf("Enter a valid command\n");
        }
    }
    return 0;
}   