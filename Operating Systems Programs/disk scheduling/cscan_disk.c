#include <stdio.h>
#include <stdlib.h>

int main() {
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
    
    // Sort the requests to serve in increasing order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    
    printf("CSCAN (Circular SCAN) Disk Scheduling:\n");
    printf("Order of service: %d", head);
    
    // Serve requests in the right direction until the end
    int index = 0;
    for (int i = head; i <= requests[n - 1]; i++) {
        printf(" -> %d", requests[index]);
        totalMovement += abs(i - requests[index]);
        index++;
    }
    
    // Return to the beginning of the disk and serve remaining requests in the right direction
    totalMovement += abs(requests[n - 1] - requests[0]);
    for (int i = 0; i <= requests[0]; i++) {
        printf(" -> %d", requests[index]);
        totalMovement += abs(i - requests[index]);
        index++;
    }
    
    printf("\nTotal head movement: %d\n", totalMovement);
    
    return 0;
}
