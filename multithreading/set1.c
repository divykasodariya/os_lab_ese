#include<stdio.h>
#include<pthread.h>

int arr[100]={1};
int partialsum[4]={0};
void* compute(void * args){
    int id = *(int*)args;
    int start= id*25;
    int end= start+25;
    for(int i = start;i<end;i++){
        partialsum[id]+=arr[i];
    }
    return NULL;
}
int main(){
    pthread_t threads[4];
    int thread_ids[4]={0,1,2,3};
    for (int i = 0; i < 100; i++) arr[i] = 1;
    for(int i = 0 ;i <4;i++){
        pthread_create(&threads[i],NULL,compute,&thread_ids[i]);
    }
    for(int i = 0; i<4;i++){
        pthread_join(threads[i],NULL);
    }
    for(int i = 0; i<4;i++){
        printf("%d ",partialsum[i]);
    }
    printf("\n");
}