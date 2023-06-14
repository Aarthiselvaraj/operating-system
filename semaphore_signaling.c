#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_INSTANCES 4
#define NUM_PROCESSES 4

sem_t semaphore;

void* process(void* arg) {
    int process_id = (int)arg;
    
    printf("Process P%d is waiting...\n", process_id);
    sem_wait(&semaphore);
    printf("Process P%d acquired the semaphore.\n", process_id);
    printf("Process P%d is using the resource.\n", process_id);
    printf("Process P%d is releasing the semaphore.\n", process_id);
    sem_post(&semaphore);

    return NULL;
}

int main() {
    pthread_t threads[NUM_PROCESSES];
    int process_ids[NUM_PROCESSES];
    int i;

    
    sem_init(&semaphore, 0, NUM_INSTANCES);

    
    for (i = 0; i < NUM_PROCESSES; i++) {
        process_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, process, &process_ids[i]);
    }

    
    for (i = 0; i < NUM_PROCESSES; i++) {
        pthread_join(threads[i], NULL);
    }

    
    sem_destroy(&semaphore);

    return 0;
}
