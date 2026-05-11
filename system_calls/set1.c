#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    int f_in = open("source.txt",O_RDONLY);
    if(f_in<0){
        printf("errpr opening file \n");
        return 1;
    }
    int f_out= open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC , 644);
    char buffer[600];
    int bytes_read;
    
    while((bytes_read= (read(f_in,&buffer,sizeof(buffer))))>0){
        write(f_out,buffer,bytes_read);
    }
    struct stat st_in, st_out;
    fstat(f_in, &st_in);
    fstat(f_out, &st_out);
    
    printf("Source size: %ld bytes\n", st_in.st_size);
    printf("Dest size: %ld bytes\n", st_out.st_size);
    close(f_in);
    close(f_out);

}