#include<stdio.h>
#include<stdlib.h>

int main() {
    int diskQueue[20], n, i, head, seekTime = 0, diff;
    
    printf("Enter the size of the Queue: ");
    scanf("%d", &n);
    
    printf("Enter the Queue: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &diskQueue[i]);
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    printf("\nMovement of Cylinders\n");
    
    // Sort the disk queue in ascending order
    for (i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diskQueue[i] > diskQueue[j]) {
                int temp = diskQueue[i];
                diskQueue[i] = diskQueue[j];
                diskQueue[j] = temp;
            }
        }
    }
    
    // Find the position to start scanning in the direction of the nearest end
    int start = 0;
    for (i = 0; i < n; i++) {
        if (diskQueue[i] > head) {
            start = i;
            break;
        }
    }
    
    // SCAN towards the higher numbered cylinders
    for (i = start; i < n; i++) {
        diff = abs(diskQueue[i] - head);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d\n", head, diskQueue[i], diff);
        head = diskQueue[i];
    }
    
    // SCAN towards the lower numbered cylinders
    if (start != 0) {
        seekTime += abs(head - 0); // Move head to cylinder 0
        printf("Move from %d to %d with seek time %d\n", head, 0, abs(head - 0));
        head = 0;
        
        for (i = start - 1; i >= 0; i--) {
            diff = abs(diskQueue[i] - head);
            seekTime += diff;
            printf("Move from %d to %d with seek time %d\n", head, diskQueue[i], diff);
            head = diskQueue[i];
        }
    }
    
    printf("\nTotal Seek Time: %d\n", seekTime);
    printf("Average Seek Time: %f\n", (float) seekTime / n);
    
    return 0;
}
