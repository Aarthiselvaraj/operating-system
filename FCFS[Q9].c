#include<stdio.h>

int main() {
    int n = 3,i;
    int pid[] = {0, 1, 2};
    int burst_time[] = {2, 4, 8};
    int waiting_time[n], turnaround_time[n];
    
    
    waiting_time[0] = 0;
    for(i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    
    for(i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    
    
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
    for(i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", pid[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    
    return 0;
}
