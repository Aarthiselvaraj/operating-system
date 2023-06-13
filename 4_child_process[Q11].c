#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid[4];
    int i, j;
    for (i = 0; i < 4; i++) {
        pid[i] = fork();
        if (pid[i] < 0) {
            printf("Error occurred while forking.\n");
            exit(1);
        } else if (pid[i] == 0) {
            
            switch (i) {
                case 0: 
                    printf("Odd numbers: ");
                    for (j = 1; j <= 10; j++) {
                        if (j % 2 != 0) {
                            printf("%d ", j);
                        }
                    }
                    break;
                case 1: 
                    printf("Even numbers: ");
                    for (j = 1; j <= 10; j++) {
                        if (j % 2 == 0) {
                            printf("%d ", j);
                        }
                    }
                    break;
                case 2: 
                    printf("Multiples of 3: ");
                    for (j = 1; j <= 10; j++) {
                        if (j % 3 == 0) {
                            printf("%d ", j);
                        }
                    }
                    break;
                case 3: 
                    printf("Multiples of 5: ");
                    for (j = 1; j <= 10; j++) {
                        if (j % 5 == 0) {
                            printf("%d ", j);
                        }
                    }
                    break;
                default:
                    break;
            }
            printf("\nProcess id: %d\n", getpid());
            exit(0);
        }
    }
    
    for (i = 0; i < 4; i++) {
        waitpid(pid[i], NULL, 0);
    }
    return 0;
}
