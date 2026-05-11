#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
int sharedcounter=0;
void * increment(void* args){
    for(int i = 0; i<5000;i++)
    {
        pthread_mutex_lock(&lock);
        sharedcounter++;
        pthread_mutex_unlock(&lock);
    }
        return NULL;
}
int main(){
    pthread_t t1;
    pthread_t t2;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&t1 , NULL , increment , NULL);
    pthread_create(&t2 , NULL , increment , NULL);
   
        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
    
    printf("%d  ",sharedcounter);
}