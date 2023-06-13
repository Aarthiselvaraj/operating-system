#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_cond_t philosophers[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopher_id = *(int *)arg;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Thinking
        printf("Philosopher %d is thinking.\n", philosopher_id);
        sleep(rand() % 3); // Simulate thinking

        // Hungry
        printf("Philosopher %d is hungry.\n", philosopher_id);

        pthread_mutex_lock(&forks[left_fork]);
        pthread_mutex_lock(&forks[right_fork]);

        // Eating
        printf("Philosopher %d is eating.\n", philosopher_id);
        state[philosopher_id] = 1;

        sleep(rand() % 3); // Simulate eating

        // Release forks
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);

        // Set state to thinking
        state[philosopher_id] = 0;

        // Signal neighbors
        pthread_cond_signal(&philosophers[(philosopher_id + 1) % NUM_PHILOSOPHERS]);
        pthread_cond_signal(&philosophers[(philosopher_id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS]);
    }
}

int main() {
    int i;
    int philosopher_ids[NUM_PHILOSOPHERS];
    pthread_t philosophers_threads[NUM_PHILOSOPHERS];

    // Initialize mutex locks and condition variables
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
        pthread_cond_init(&philosophers[i], NULL);
        state[i] = 0;
    }

    // Create philosopher threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers_threads[i], NULL, philosopher, &philosopher_ids[i]);
    }

    // Wait for philosopher threads to finish
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers_threads[i], NULL);
    }

    // Destroy mutex locks and condition variables
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
        pthread_cond_destroy(&philosophers[i]);
    }

    return 0;
}
