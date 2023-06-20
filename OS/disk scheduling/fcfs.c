#include<stdio.h>
#include<stdlib.h>

int main() {
    int diskQueue[20], n, i, seekTime = 0, diff;
    
    printf("Enter the size of the Queue: ");
    scanf("%d", &n);
    
    printf("Enter the Queue: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &diskQueue[i]);
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &diskQueue[n]); // head element
    
    printf("\nMovement of Cylinders\n");
    for (i = 0; i < n; i++) {
        diff = abs(diskQueue[i + 1] - diskQueue[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d\n", diskQueue[i], diskQueue[i + 1], diff);
    }
    
    printf("\nTotal Seek Time: %d\n", seekTime);
    printf("Average Seek Time: %f\n", (float) seekTime / n);
    
    return 0;
}
