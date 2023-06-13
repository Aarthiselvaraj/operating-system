#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void* process(void* arg) {
    int process_id = ((int)arg);
    printf("Process P%d is waiting...\n", process_id);
    sem_wait(&semaphore);
    printf("Process P%d has acquired the semaphore.\n", process_id);
    printf("Process P%d is executing...\n", process_id);
    printf("Process P%d is releasing the semaphore.\n", process_id);
    sem_post(&semaphore);
    printf("Process P%d has released the semaphore.\n", process_id);
    pthread_exit(NULL);
}

int main() {
	int i;
    int num_instances = 4;
    int num_processes = 4;
    sem_init(&semaphore, 0, num_instances);

    pthread_t threads[num_processes];
    int process_ids[num_processes];

    // Creating threads for each process
    for(i=0;i<num_processes;i++) {
        process_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, process, (void*)&process_ids[i]);
    }

    // Waiting for all threads to finish
    for (i = 0; i < num_processes; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);

    // P5 wants the same resource
    printf("Process P5 is waiting...\n");
    sem_wait(&semaphore);
    printf("Process P5 has acquired the semaphore.\n");
    printf("Process P5 is executing...\n");
    printf("Process P5 is releasing the semaphore.\n");
    sem_post(&semaphore);
    printf("Process P5 has released the semaphore.\n");

    return 0;
}
