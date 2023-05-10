#include <stdio.h>
int main()
{
	int n=4,total_waiting_time=0,total_turnaround_time=0;
	int processes[n],burst_time[n],completion_time[n],waiting_time[n],turn_around_time[n];
	int i,j,smallest,temp;
	float avg_waiting_time,avg_turnaround_time;
	printf("enter the burst time for processes:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:",i+1);
		scanf("%d",&burst_time[i]);
		processes[i]=i+1;
		
	}
	for(i=0;i<n;i++)
	{
		smallest=i;
		for(j=i+1;j<n;j++){
			if(burst_time[j]<burst_time[smallest])
			{
				smallest=j;
			}
		}
		temp=burst_time[i];
		burst_time[i]=burst_time[smallest];
		burst_time[smallest]=temp;
		temp=processes[i];
		processes[i]=processes[smallest];
		processes[smallest]=temp;
		
		
	}
	for(i=0;i<n;i++){
		if(i==0)
		{
			completion_time[i]=burst_time[i];
		}
		else{
			completion_time[i]=completion_time[i-1]+burst_time[i];
		}
	}
	for(i=0;i<n;i++)
	{
		waiting_time[i]=completion_time[i]-burst_time[i];
		turn_around_time[i]=completion_time[i];
		total_waiting_time+=waiting_time[i];
		total_turnaround_time+=turn_around_time[i];
	}
	printf("\nProcess\t Burst time\t waiting_time\t turnaround_time\n ");
	for(i=0;i<n;i++){
		printf("P[%d]\t\t %d\t\t %d\t\t %d\n",processes[i],burst_time[i],waiting_time[i],turn_around_time[i]);
	}
	avg_waiting_time=(float)total_waiting_time/n;
	avg_turnaround_time=(float)total_turnaround_time/n;
	printf("\nAverage waiting time = %.2f",avg_waiting_time);
	printf("\nAverage turnaround time = %.2f",avg_turnaround_time);
	return 0;
}
