#include<stdio.h>
#define P 5 
#define R 3 

int main() {
    int Allocation[P][R] = { {1, 1, 2}, {2, 1, 2}, {3, 0, 1}, {0, 2, 0}, {1, 1, 2} };
    int Max[P][R] = { {5, 4, 4}, {4, 3, 3}, {9, 1, 3}, {8, 6, 4}, {2, 2, 3} };
    int Available[R] = {3, 2, 1}; 

    int Need[P][R];
    int i,j;

    
    for(i=0; i<P; i++) {
        for(j=0; j<R; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    
    printf("Need matrix:\n");
    for(i=0; i<P; i++) {
        printf("P%d: ", i);
        for(j=0; j<R; j++) {
            printf("%d ", Need[i][j]);
        }
        printf("\n");
    }

    return 0;
}
