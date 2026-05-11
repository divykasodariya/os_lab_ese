
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, write_lock;
int read_count = 0;

void* writer(void* arg) {
    for(int i=0; i<3; i++) {
        sem_wait(&write_lock);
        printf("Journalist is writing...\n");
        sleep(1);
        sem_post(&write_lock);
        sleep(1);
    }
    return NULL;
}

void* reader(void* arg) {
    int id = *(int*)arg;
    for(int i=0; i<3; i++) {
        sem_wait(&mutex);
        read_count++;
        if (read_count == 1) sem_wait(&write_lock); // First reader locks writer
        sem_post(&mutex);

        printf("Editor %d is reading...\n", id);
        sleep(1);

        sem_wait(&mutex);
        read_count--;
        if (read_count == 0) sem_post(&write_lock); // Last reader unlocks writer
        sem_post(&mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t w, r1, r2;
    int id1 = 1, id2 = 2;

    sem_init(&mutex, 0, 1);
    sem_init(&write_lock, 0, 1);

    pthread_create(&w, NULL, writer, NULL);
    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&r2, NULL, reader, &id2);

    pthread_join(w, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);

    return 0;
}