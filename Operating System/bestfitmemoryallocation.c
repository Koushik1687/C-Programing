#include <stdio.h>

#define BLOCKS 5
#define PROCESSES 4

int main() {
    int memoryBlocks[BLOCKS] = {100, 500, 200, 300, 600};
    int processes[PROCESSES] = {212, 417, 112, 426};

    int allocation[PROCESSES]; 
    for (int i = 0; i < PROCESSES; i++) {
        allocation[i] = -1;  
    }

    for (int i = 0; i < PROCESSES; i++) {
        int bestFitIndex = -1;
        for (int j = 0; j < BLOCKS; j++) {
            if (memoryBlocks[j] >= processes[i]) {
                if (bestFitIndex == -1 || memoryBlocks[j] < memoryBlocks[bestFitIndex]) {
                    printf("memoryBlocks : %d\n",memoryBlocks[j]);
                    printf("memoryBlocks : %d\n",memoryBlocks[bestFitIndex]);
                    bestFitIndex = j;
                    printf("bestFitIndex : %d\n",bestFitIndex);
                    printf("\n");
                }
            }
        }
        if (bestFitIndex != -1) {
            allocation[i] = bestFitIndex;
            memoryBlocks[bestFitIndex] -= processes[i]; 
        }
    }

   
    for (int i = 0; i < PROCESSES; i++) {
        printf("Process %d --> ", processes[i]);
        if (allocation[i] != -1) {
            printf("Block %d\n", memoryBlocks[allocation[i]] + processes[i]);
        } else {    
            printf("Not Allocated\n");
        }
    }

    return 0;
}
