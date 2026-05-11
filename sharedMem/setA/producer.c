#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    // 1. Create shared memory segment (Key: 1234, Size: 1024 bytes)
    int shmid = shmget(1234, 1024, 0666 | IPC_CREAT); 
    
    // 2. Attach to shared memory
    int *shared_memory = (int*) shmat(shmid, NULL, 0);

    // 3. Write 5 temperature values
    for (int i = 0; i < 5; i++) {
        shared_memory[i] = 25 + i; // Writing temp values 25, 26, 27...
        printf("Sensor recorded temp: %d°C\n", shared_memory[i]);
    }

    // 4. Detach from shared memory
    shmdt(shared_memory); 
    return 0;
}