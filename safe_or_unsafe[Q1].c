#include <stdio.h>
int main()
{
	int claim[4][3]={{3,2,2},{6,1,3},{3,1,4},{4,2,2}};
	int allocation[4][3]={{1,0,0},{6,1,2},{2,1,1},{0,0,2}};
	int available[3]={9,3,6};
	int finish[4]={0};
	int work[3]={0};
	int i,j,k;
	for(  i=0; i<3; i++)
	{
		work[i]=available[i];
	}
	int need[4][3];
	for(i=0;i<4;i++)
	{
		for( j=0;j<3;j++)
		{
			need[i][j]=claim[i][j]-allocation[i][j];
		}
	}
	int safe=0;
	int sequence[4];
	int count=0;
	while(count<4)
	{
		int found=0;
		for(i=0;i<4;i++)
		{
			if(!finish[i]){
				for(j=0;j<3;j++)
				{
					if(need[i][j]>work[j]){
						break;
					}
				}
				if(j==3){
					for(k=0;k<3;k++){
						work[k]+=allocation[i][k];
						
					}
					finish[i]=1;
					sequence[count]=i;
					count++;
					found=1;
				}
			}
		}
		if(!found){
			break;
		}
	}
	if(count==4){
		printf("safe sequence:");
		for(i=0;i<4;i++){
		printf("%d",sequence[i]);
		}
		printf("\nThe system is in safe state \n");
		safe=1;
		}
	else{
		printf("the system is in an unsafe state\n");
	}
	return safe;
}




