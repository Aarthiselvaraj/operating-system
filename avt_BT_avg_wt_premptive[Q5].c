#include<stdio.h>

struct process {
    char name[3];
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int remaining_time;
    int is_completed;
};

int main() {
	int i;
    struct process processes[4];
    int current_time = 0, total_burst_time = 0, completed = 0;
    float avg_turnaround_time = 0, avg_waiting_time = 0;

    
    for(i = 0; i < 4; i++) {
        printf("Enter details for Process P%d:\n", i+1);
        processes[i].name[0] = 'P';
        processes[i].name[1] = i + 49;
        processes[i].name[2] = '\0';
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].is_completed = 0;
        total_burst_time += processes[i].burst_time;
    }

    
    while(completed != 4) {
        int shortest_time = 9999, next_process;
        for(i = 0; i < 4; i++) {
            if(processes[i].arrival_time <= current_time && !processes[i].is_completed && processes[i].remaining_time < shortest_time) {
                shortest_time = processes[i].remaining_time;
                next_process = i;
            }
        }
        processes[next_process].remaining_time--;

        if(processes[next_process].remaining_time == 0) {
            processes[next_process].is_completed = 1;
            processes[next_process].completion_time = current_time + 1;
            processes[next_process].turnaround_time = processes[next_process].completion_time - processes[next_process].arrival_time;
            processes[next_process].waiting_time = processes[next_process].turnaround_time - processes[next_process].burst_time;
            avg_turnaround_time += processes[next_process].turnaround_time;
            avg_waiting_time += processes[next_process].waiting_time;
            completed++;
        }

        current_time++;
    }

    
    avg_turnaround_time /= 4;
    avg_waiting_time /= 4;

    
    printf("\nProcess\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");
    for(i = 0; i < 4; i++) {
        printf("%s\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", processes[i].name, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);

    return 0;
}
