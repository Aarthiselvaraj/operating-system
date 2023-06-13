#include <stdio.h>

int main()
{
    int n = 3; 
    int pages[] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3}; 
    int frames[n]; 
    int faults = 0; 
    int i, j, k, min, flag, max;

    for(i = 0; i < n; i++) {
        frames[i] = -1; 
    }

    for(i = 0; i < 20; i++) {
        flag = 0;

        
        for(j = 0; j < n; j++) {
            if(pages[i] == frames[j]) {
                flag = 1; 
                break;
            }
        }

        // if page is not in page frames, replace LRU page
        if(flag == 0) {
            faults++;
            min = 100; // initialize min to a large value
            for(j = 0; j < n; j++) {
                for(k = i - 1; k >= 0; k--) {
                    if(pages[k] == frames[j] && k < min) {
                        min = k; // find the least recently used page
                        max = j; // find the corresponding page frame
                    }
                }
            }
            frames[max] = pages[i]; // replace LRU page with current page
        }

        // print current page frames
        for(j = 0; j < n; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", faults);

    return 0;
}
