#include<stdio.h>
int main()
{
	int n,i,j,k,count=0,page_faults=0;
	int frames[10],pages[30],temp[10];
	printf("enter number of frames:");
	scanf("%d",&n);
	printf("enter the page reference sequence : ");
	for(i=0;i<8;i++){
		scanf("%d",&pages[i]);
	}
	for(i=0;i<n;i++){
		frames[i]=-1;
	}
	for(i=0;i<8;i++){
		int flag=0;
		for(j=0;j<n;j++){
			if(frames[j]==pages[i]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			frames[count]=pages[i];
			count=(count+1)%n;
			page_faults++;
		}
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",frames[j]);
		}
	}
	printf("\nTotal number of page faults=%d\n",page_faults);
	return 0;
	
}
