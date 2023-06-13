#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void cscan(int tracks[], int n, int head) {
    int i, j, distance = 0;
    int start = head;
    int end = tracks[n - 1];
    int found = 0;

    qsort(tracks, n, sizeof(int), cmpfunc);

    // Move the head to the end of the disk
    for (i = start; i <= end; i++) {
        distance += abs_diff(head, tracks[i]);
        head = tracks[i];
    }

    // Move the head to the beginning of the disk
    distance += abs_diff(head, tracks[0]);
    head = tracks[0];

    // Find the requested track
    for (i = 0; i < n; i++) {
        if (tracks[i] >= start) {
            found = i;
            break;
        }
    }

    // Move the head from the beginning to the requested track
    for (i = found; i < n; i++) {
        distance += abs_diff(head, tracks[i]);
        head = tracks[i];
    }

    // Move the head to the end of the disk again
    for (i = 0; i < found; i++) {
        distance += abs_diff(head, tracks[i]);
        head = tracks[i];
    }

    printf("Average head movement: %.2f\n", (float)distance / n);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head = 50; // starting head position

    cscan(tracks, n, head);

    return 0;
}
