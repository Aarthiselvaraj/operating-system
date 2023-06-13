#include<stdio.h>
#include<stdlib.h>
void sortTracks(int *tracks,int numTracks) {
	int i,j,temp;
	for(i=0;i<numTracks-1;i++){
		for(j=0;j<numTracks-1;j++){
			if(tracks[j]>tracks[j+1]) {
				temp=tracks[j];
				tracks[j]=tracks[j+1];
				tracks[j+1]=temp;
			}
		}
	}
}
int findClosestTrack(int *tracks,int numTracks,int headPos,int direction){
	int closestTrack=-1;
	if(direction==1){
		for(i=0;i<numTracks;i++) {
			if(tracks[i]>=headPos) {
				closestTrack=i;
				break;
			}
		}
	} else {
		for(i=numTracks-1;i>=0;i--) {
			if(tracks[i]<=headPos){
				closestTrack=i;
				break;
			}
		}
		
	}
	return closestTrack;
}
int main() {
	int numTracks=9;
	int tracks={55,58,60,70,18,19,150,160,184};
	int headPos=50;
	int direction=1;
	int totalHeadMovement=0;
	int numRequests=numTracks;
	sortTracks(tracks,numTracks);
	int closestTrack = findClosestTrack(tracks, numTracks, headPos, direction);
    
    while (numRequests > 0) {
        // Move the head to the closest track
        headPos = tracks[closestTrack];
        printf("Head moved to track %d\n", headPos);
        
        // Update the total head movement
        totalHeadMovement += abs(headPos - tracks[closestTrack]);
        
        // Remove the serviced track from the list
        for (int i = closestTrack; i < numTracks - 1; i++) {
            tracks[i] = tracks[i + 1];
        }
        
        numTracks--;
        numRequests--;
        
        if (numTracks == 0) {
            break;
        }
        
        // Change direction if the head reaches the first or last track
        if (headPos == tracks[0]) {
            direction = 1;
        } else if (headPos == tracks[numTracks - 1]) {
            direction = 0;
        }
        
        // Find the index of the track closest to the head position in the updated direction
        closestTrack = findClosestTrack(tracks, numTracks, headPos, direction);
    }
    
    // Print the average head movement
    float averageHeadMovement = (float)totalHeadMovement / numRequests;
    printf("Average head movement: %.2f\n", averageHeadMovement);
    
    return 0;
}
}
