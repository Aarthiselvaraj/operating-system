#include <stdio.h>
#include <pthread.h>

void *printEven(void *arg)
{
    int n = *((int *)arg);
    int i;
    printf("Even Numbers: ");
    for (i = 2; i <= n; i += 2)
    {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

void *printOdd(void *arg)
{
    int n = *((int *)arg);
    int i;
    printf("Odd Numbers: ");
    for (i = 1; i <= n; i += 2)
    {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    pthread_t evenThread, oddThread;

    
    if (pthread_create(&evenThread, NULL, printEven, (void *)&n) != 0)
    {
        printf("Failed to create even thread.\n");
        return 1;
    }

    
    if (pthread_create(&oddThread, NULL, printOdd, (void *)&n) != 0)
    {
        printf("Failed to create odd thread.\n");
        return 1;
    }

    
    if (pthread_join(evenThread, NULL) != 0)
    {
        printf("Failed to join even thread.\n");
        return 1;
    }

    if (pthread_join(oddThread, NULL) != 0)
    {
        printf("Failed to join odd thread.\n");
        return 1;
    }

    return 0;
}
