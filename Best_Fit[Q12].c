#include<stdio.h>
int main(){
	int i,j,n,m,p[10],mp[10],a[10];
	printf("enter the number of memory partitions : ");
	scanf("%d",&m);
	printf("enter the memory partitions size (in KB)\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&mp[i]);
		a[i]=0;
	}
	printf("enter the number of process:");
	scanf("%d",&n);
	printf("enter the process size(in KB)\n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++){
		int bestfit=-1;
		for(j=0;j<m;j++){
			if(mp[j]>=p[i]&&a[j]==0){
				if(bestfit==-1)
				{
					bestfit=j;
				}
				else if(mp[j]<mp[bestfit]){
					bestfit=j;
				}
			}
		}
		if(bestfit!=-1){
			a[bestfit]=p[i];
			printf("\nprocess %d of size %d KB allocated in partition %d of size %d KB\n"
			,i+1,p[i],bestfit+1,mp[bestfit]);
			
		}else{
			printf("\nprocess %d of size %d KB cannot be allocated\n",i+1,p[i]);
		}
	}
	return 0;
}
	

