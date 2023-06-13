#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 5,i; 
    int tracks[] = {55, 58, 60, 70, 18}; 
    int head = 50; 
    int movement = 0; 

    printf("Initial head position: %d\n", head);

    
    for (i = 0; i < n; i++) {
        int distance = abs(tracks[i] - head); 
        movement += distance; 
        head = tracks[i]; 
        printf("Moved to track %d, distance = %d\n", head, distance);
    }

    printf("Total head movement = %d\n", movement);
    printf("Average head movement = %.2f\n", (float)movement / n);

    return 0;
}
