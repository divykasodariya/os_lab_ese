#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    // 1. Create POSIX shared memory object
    int fd = shm_open("/gamescore", O_CREAT | O_RDWR, 0666);
    
    // 2. Configure the size of the shared memory
    ftruncate(fd, sizeof(int));
    
    // 3. Map shared memory to process address space
    int *score = mmap(0, sizeof(int), PROT_WRITE, MAP_SHARED, fd, 0);

    // 4. Update scores with a delay
    *score = 100;
    printf("Game Engine: Score set to 100\n");
    sleep(1);
    
    *score = 200;
    printf("Game Engine: Score set to 200\n");
    sleep(1);
    
    *score = 300; 
    printf("Game Engine: Score set to 300\n");

    // 5. Unmap memory
    munmap(score, sizeof(int));
    return 0;
}