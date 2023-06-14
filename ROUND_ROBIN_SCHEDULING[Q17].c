#include<stdio.h>
#define MAX_PROCESSES 3
#define QUANTUM_TIME 4
struct process {
	int burst_time;
	int waiting_time;
	int turnaround_time;
};
int main(){
	struct process processes[MAX_PROCESSES]={
		{24,0,0},
		{3,0,0},
		{3,0,0}
	};
	int i,total_waiting_time=0,total_turnaround_time=0,completed_processes=0, time_elapsed=0;
	while(completed_processes < MAX_PROCESSES) {
		for(i=0;i<MAX_PROCESSES;i++)
		{
			if(processes[i].burst_time>0){
				if(processes[i].burst_time<=QUANTUM_TIME){
					time_elapsed+=processes[i].burst_time;
					processes[i].turnaround_time=time_elapsed;
					processes[i].waiting_time=processes[i].turnaround_time-processes[i].burst_time;
					total_waiting_time+=processes[i].waiting_time;
					total_turnaround_time+=processes[i].turnaround_time;
					processes[i].burst_time=0;
					completed_processes++;
				} else{
					time_elapsed+=QUANTUM_TIME;
					processes[i].burst_time-=QUANTUM_TIME;
					
				}
			}
		}
	}
	double avg_waiting_time=(double)total_waiting_time/MAX_PROCESSES;
	double avg_turnaround_time=(double)total_turnaround_time/MAX_PROCESSES;
	printf("average waiting time:%.2f ms\n",avg_waiting_time);
	printf("average turnaround time:%.2f ms\n",avg_turnaround_time);
	return 0;
	
	
}

