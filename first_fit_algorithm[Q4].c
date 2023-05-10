#include<stdio.h>
#define MAX_PARTITIONS 100
int main()
{
	int partitions[MAX_PARTITIONS],n_partitions,i,j;
	int processes[]={115,500,358,200,375};
	int n_processes=sizeof(processes)/sizeof(int);
	int allocated[MAX_PARTITIONS]={0};
	printf("enter the number of memory partitions : ");
	scanf("%d",&n_partitions);
	printf("enter the size of each memory partition:\n");
	for(i=0;i<n_partitions;i++){
		scanf("%d",&partitions[i]);
	}
	for(i=0;i<n_partitions;i++){
		for(j=0;j<n_partitions;j++){
			if(!allocated[j] && processes[i]<=partitions[j]){
				allocated[j]=1;
				printf("process %d allocated to partition %d (size %d KB)\n",i+1,j+1,partitions[j]);
				break;
			}
		}
		if(j==n_partitions){
			printf("process %d cannot be allocated\n",i+1);
		}
	}
	return 0;
}
