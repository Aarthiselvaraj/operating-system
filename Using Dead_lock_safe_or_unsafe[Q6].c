#include <stdio.h>
#define N 3   
int main()
{
    int allocation[N][N] = { {3, 3, 3},
                             {2, 0, 3},
                             {1, 2, 4} };

    int max[N][N] = { {3, 6, 8},
                      {4, 3, 3},
                      {3, 4, 4} };

    int available[N] = {1, 2, 0};

    int need[N][N];
    int i,j,k;

    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    
    int finish[N] = {0};

    
    int work[N];
    for (i = 0; i < N; i++) {
        work[i] = available[i];
    }

    
    int count = 0;
    int safe_seq[N];
    while (count < N) {
                int found = 0;
        for (i = 0; i < N; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < N; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == N) {
                    
                    for (k = 0; k < N; k++) {
                        work[k] += allocation[i][k];
                    }
                    safe_seq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            
            printf("System is in deadlock state.\n");
            printf("Deadlocked processes: ");
            for (i = 0; i < N; i++) {
                if (finish[i] == 0) {
                    printf("%d ", i);
                }
            }
            printf("\n");
            return 0;
        }
    }

    
    printf("System is in safe state.\n");
    printf("Safe sequence: ");
    for (i = 0; i < N; i++) {
        printf("%d ", safe_seq[i]);
    }
    printf("\n");

    return 0;
}
