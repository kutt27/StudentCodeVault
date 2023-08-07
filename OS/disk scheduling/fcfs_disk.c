#include <stdio.h>
#include <stdlib.h>

int abs(int a){
	return a < 0 ? -a : a;
}

int main(){
	int n, head, totalMovement = 0;
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    int requests[n];
    
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    printf("FCFS Disk Scheduling:\n");
    printf("Order of service: %d", head);

    totalMovement = abs(head - requests[0]);
    for(int i = 1; i < n; i++){
    	printf("--> %d", requests[i]);
    	totalMovement += abs(requests[i] - requests[i - 1]);
    }

    printf("\nTotal head movement: %d\n", totalMovement);

    return 0;
}