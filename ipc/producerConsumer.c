#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_ITEMS 5

sem_t empty, full, mutex;
int shelf[MAX_ITEMS];
int in = 0, out = 0, item_num = 1;

void* baker(void* arg) {
    // Let's say the baker produces 6 items total
    for (int i = 0; i < 6; i++) { 
        sem_wait(&empty); // Wait if shelf is full
        sem_wait(&mutex); // Lock the shelf
        
        shelf[in] = item_num;
        printf("Baker baked item %d at slot %d\n", item_num, in);
        item_num++;
        in = (in + 1) % MAX_ITEMS; // Circular array
        
        sem_post(&mutex); // Unlock the shelf
        sem_post(&full);  // Signal that a new item is available
        
        sleep(1); // Bake time
    }
    return NULL;
}

void* customer(void* arg) {
    int id = *(int*)arg;
    
    // Let's say each of the 3 customers wants to buy 2 items
    for (int i = 0; i < 2; i++) { 
        sem_wait(&full);  // Wait if shelf is empty
        sem_wait(&mutex); // Lock the shelf
        
        int item = shelf[out];
        printf("Customer %d bought item %d from slot %d\n", id, item, out);
        out = (out + 1) % MAX_ITEMS; // Circular array
        
        sem_post(&mutex); // Unlock the shelf
        sem_post(&empty); // Signal that a slot is now empty
        
        sleep(2); // Consume time
    }
    return NULL;
}

int main() {
    pthread_t b, c[3];
    int c_ids[3] = {1, 2, 3};

    // Initialize semaphores
    sem_init(&empty, 0, MAX_ITEMS); // Starts with 5 empty slots
    sem_init(&full, 0, 0);          // Starts with 0 full slots
    sem_init(&mutex, 0, 1);         // Binary semaphore for mutual exclusion

    // Create threads
    pthread_create(&b, NULL, baker, NULL);
    for (int i = 0; i < 3; i++) {
        pthread_create(&c[i], NULL, customer, &c_ids[i]);
    }

    // Join threads
    pthread_join(b, NULL);
    for (int i = 0; i < 3; i++) {
        pthread_join(c[i], NULL);
    }

    return 0;
}