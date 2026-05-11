#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();
    if(pid<0){
        printf("error\n");
        return 1;
    }
    else if (pid==0){
        int f_in = open("attendence.txt",O_APPEND| O_WRONLY | O_CREAT ,0644);
        char buffer[]="child attended\n";
        write(f_in,buffer,sizeof(buffer)-1);
        close(f_in);
    }
    else{
         int f_in = open("attendence.txt",O_APPEND| O_WRONLY | O_CREAT,0644);
        char buffer[]="parent attended\n";
        write(f_in,buffer,sizeof(buffer)-1);
        close(f_in);
    }
}