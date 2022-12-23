#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc , char *argv[]){
    char *token = argv[0];
    if(strcmp(token , "./DATE_code")==0){
        token = argv[1];
    }
    if(strcmp(token , "ate")==0 || strlen(token) == 0){
        time_t tm;
        time(&tm);
        if(tm == -1){
            printf("Error in time function\n");
        }
        else{
            printf("%s", ctime(&tm));
        }
    }
    else if(strcmp(token , "-u") == 0){
        time_t tm;
        time(&tm);
		struct tm *utc=gmtime(&tm);
		if(utc==NULL){
			printf("Error in time function \n");
		}
        else{
		    printf("UTC : %s",asctime(utc));
        }
    }
    else if(strcmp(token , "-R") == 0){
        time_t tm;
        time(&tm);
        if(tm == -1){
            printf("Error in time function\n");
        }
        else{
            time_t tm;
            time(&tm);
            struct tm *lt=localtime(&tm);
            char day[3];
            char month[3];
            for(int i=0; i<3; i++){
                day[i]=asctime(lt)[i];
            }
            printf("%s, ",day);
            for(int i=0; i<3; i++){
                month[i]=asctime(lt)[i+4];
            }
            printf("%d %s" ,lt->tm_mday,month );
            char time_code[]="0000";
            if((lt->tm_zone , "IST")==0){
                strcpy(time_code,"0530");
            }
            printf("%d %d:%d:%d +%s \n",lt->tm_year+1900,lt->tm_hour,lt->tm_min,lt->tm_sec,time_code);
        }
    }
    else{
        printf("Invalid Command\n");
    }
    return 0;
}