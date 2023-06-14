#include<stdio.h>
int main(){
	int n=3,i;
	int burst_time[]={10,15,25};
	int waiting_time[n],turnaround_time[n];
	waiting_time[0]=0;
	for(i=1;i<n;i++){
		waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
	}
	for(i=0;i<n;i++)
	{
		turnaround_time[i]=waiting_time[i]+burst_time[i];
	}
	float avg_waiting_time=0,avg_turnaround_time=0;
	for(i=0;i<n;i++){
		avg_waiting_time+=waiting_time[i];
		avg_turnaround_time+=turnaround_time[i];
	}
	avg_waiting_time /=n;
	avg_turnaround_time /=n;
	printf("process\tBurst Time\tWaiting time\tTurnaround time\n");
	for(i=0;i<n;i++){
		printf("P%d\t\t%d\t\t%d\n",i+1,burst_time[i],waiting_time[i],turnaround_time[i]);
	}
	printf("Average waiting time:%.2f\n",avg_waiting_time);
	printf("Average turnaround time:%.2f\n",avg_turnaround_time);
	return 0;
}
