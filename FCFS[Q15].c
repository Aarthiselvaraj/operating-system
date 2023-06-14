#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=9,i;
	int tracks[]={55,58,60,70,18,90,150,160,184};
	int head=50;
	int distance=0;
	for(i=0;i<n;i++){
		distance+=abs(head-tracks[i]);
		head=tracks[i];
	}
	printf("average head movement :%2f\n",(float)distance/n);
	return 0;
}
