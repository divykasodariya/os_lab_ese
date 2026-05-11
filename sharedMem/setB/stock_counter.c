#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>

// Define a structure to hold both the semaphore and the counter
struct shared_data {
    sem_t mutex;
    int counter;
};

int main() {
    // 1. Create shared memory for the structure
    int shmid = shmget(IPC_PRIVATE, sizeof(struct shared_data), 0666 | IPC_CREAT);
    struct shared_data *data = (struct shared_data*) shmat(shmid, NULL, 0);

    // 2. Initialize semaphore in shared memory (pshared = 1)
    sem_init(&data->mutex, 1, 1);
    data->counter = 0;

    pid_t pid = fork();

    if (pid > 0) { // Parent Process (Writer)
        for (int i = 0; i < 10; i++) {
            sem_wait(&data->mutex);
            data->counter++;
            printf("Writer: Incremented counter to %d\n", data->counter);
            sem_post(&data->mutex);
            usleep(100000); // Small delay
        }
        wait(NULL); // Wait for child to finish
        
        // Cleanup
        sem_destroy(&data->mutex);
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
        
    } else if (pid == 0) { // Child Process (Reader)
        for (int i = 0; i < 10; i++) {
            sem_wait(&data->mutex);
            printf("Reader: Read counter value %d\n", data->counter);
            sem_post(&data->mutex);
            usleep(150000); // Slightly different delay
        }
        shmdt(data);
    }

    return 0;
}