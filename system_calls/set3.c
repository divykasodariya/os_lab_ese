#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>

int main(){
    int fd[2];
    pipe(fd);
    pid_t p = fork();
    
    if(p<0){
        printf("error opening file \n");
        return 1 ;
    }
    else if(p>0){
        // parent 
        close(fd[0]);
        char buffer[]="Hello from Parent";
        write(fd[1],buffer,sizeof(buffer)-1);
        
    }
    else{
        // child 

        // simple logic close the other thing that is open 
        close(fd[1]);
        char buffer[100];
        read(fd[0],buffer,sizeof(buffer));
        for(int i = 0; buffer[i]!='\0';i++){
            buffer[i]=toupper(buffer[i]);
        }
        // idhar dhyan dena %c and not &buffer[i]
        for(int i = 0; buffer[i]!='\0';i++){
            printf("%c",buffer[i]);
        }
        close(fd[0]);
    }
}