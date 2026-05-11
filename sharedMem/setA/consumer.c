#include <stdio.h>
#include <sys/shm.h>

int main() {
    // 1. Access the existing shared memory segment
    int shmid = shmget(1234, 1024, 0666); 
    
    // 2. Attach to shared memory
    int *shared_memory = (int*) shmat(shmid, NULL, 0);

    // 3. Read the 5 temperature values
    for (int i = 0; i < 5; i++) {
        printf("Display reading temp: %d°C\n", shared_memory[i]);
    }

    // 4. Detach and destroy shared memory
    shmdt(shared_memory); 
    shmctl(shmid, IPC_RMID, NULL); 
    
    return 0;
}