#include <stdio.h>

#define MAX_BLOCKS 100

// Structure to represent a memory block
typedef struct {
    int id;         // Block ID
    int size;       // Block size
    int allocated;  // Flag to indicate if the block is allocated or not
} Block;

// Function to allocate memory using First Fit algorithm
void allocateFirstFit(Block blocks[], int numBlocks, int processID, int processSize) {
    int i;
    for (i = 0; i < numBlocks; i++) {
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize) {
            blocks[i].allocated = 1;
            printf("Process %d allocated to block %d\n", processID, blocks[i].id);
            break;
        }
    }
    if (i == numBlocks) {
        printf("Process %d cannot be allocated\n", processID);
    }
}

// Function to allocate memory using Best Fit algorithm
void allocateBestFit(Block blocks[], int numBlocks, int processID, int processSize) {
    int bestFit = -1;
    int i;
    for (i = 0; i < numBlocks; i++) {
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize) {
            if (bestFit == -1 || blocks[i].size < blocks[bestFit].size) {
                bestFit = i;
            }
        }
    }
    if (bestFit != -1) {
        blocks[bestFit].allocated = 1;
        printf("Process %d allocated to block %d\n", processID, blocks[bestFit].id);
    } else {
        printf("Process %d cannot be allocated\n", processID);
    }
}

// Function to allocate memory using Worst Fit algorithm
void allocateWorstFit(Block blocks[], int numBlocks, int processID, int processSize) {
    int worstFit = -1;
    int i;
    for (i = 0; i < numBlocks; i++) {
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize) {
            if (worstFit == -1 || blocks[i].size > blocks[worstFit].size) {
                worstFit = i;
            }
        }
    }
    if (worstFit != -1) {
        blocks[worstFit].allocated = 1;
        printf("Process %d allocated to block %d\n", processID, blocks[worstFit].id);
    } else {
        printf("Process %d cannot be allocated\n", processID);
    }
}

int main() {
    Block blocks[MAX_BLOCKS];
    int numBlocks, numProcesses, i;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);
    for (i = 0; i < numBlocks; i++) {
        blocks[i].id = i;
        printf("Enter the size of block %d: ", i);
        scanf("%d", &blocks[i].size);
        blocks[i].allocated = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    for (i = 0; i < numProcesses; i++) {
        int processID, processSize;

        printf("Enter the ID of process %d: ", i);
        scanf("%d", &processID);
        printf("Enter the size of process %d: ", i);
        scanf("%d", &processSize);

        // First Fit allocation
        allocateFirstFit(blocks, numBlocks, processID, processSize);

        // Best Fit allocation
        allocateBestFit(blocks, numBlocks, processID, processSize);

        // Worst Fit allocation
        allocateWorstFit(blocks, numBlocks, processID, processSize);
    }

    return 0;
}
