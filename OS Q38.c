#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) 
{
	int i,j;
    for (i = 0; i < n-1; i++) 
	{
        for (j = 0; j < n-i-1; j++) 
		{
            if (arr[j] > arr[j+1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int findDiskIndex(int arr[], int n, int disk) 
{
    int i;
	for (i = 0; i < n; i++) 

	{
        if (arr[i] == disk) 
		{
            return i;
        }
    }
    return -1;
}
int calculateHeadMovement(int arr[], int n, int start) 
{
    int index = findDiskIndex(arr, n, start);
    int headMovement = 0;
    int i;

    if (index == -1) 
	{
        printf("Invalid disk position!\n");
        return -1;
    }

    sort(arr, n);

    printf("Disk Scheduling Order: ");
    printf("%d ", start);
    for (i = index+1; i < n; i++)  
	{
        printf("%d ", arr[i]);
        headMovement += abs(arr[i] - arr[i-1]);
    }

    for (i = index-1; i >= 0; i--) 
	{
        printf("%d ", arr[i]);
        headMovement += abs(arr[i] - arr[i+1]);
    }

    printf("\n");

    return headMovement;
}

int main() 
{
    int n, start,i;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int diskQueue[n];

    printf("Enter the disk queue:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &diskQueue[i]);
    }

    printf("Enter the starting disk position: ");
    scanf("%d", &start);

    int headMovement = calculateHeadMovement(diskQueue, n, start);

    if (headMovement != -1) 
	{
        float averageHeadMovement = (float)headMovement / n;
        printf("\nAverage Head Movement: %.2f\n", averageHeadMovement);
    }

    return 0;
}
