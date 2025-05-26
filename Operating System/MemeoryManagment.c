// Q4. Memory Management: First-Fit Allocation (ROLL 15-20)

// Problem:
// Given a set of memory blocks and process sizes, allocate using First-Fit.

//  Input Format:
// Memory Blocks: [100, 500, 200, 300, 600]
// Processes: [210, 415, 118, 422]

// Expected Output:
// Process 210 → Block 500
// Process 415 → Block 600
// Process 118 → Block 200
// Process 422 → Not allocated


// Student Name :
// Assignment Group 4
// 1. Koushik Paul 
// 2. Subhranil Srimani
// 3. Tiyasha Biswas
// 4. Chandrima Sarkar
// 5. Soumyodip Mukherjee
// 6. Arnab Kamakar




#include <stdio.h>

int main() {
    int i, j;

    int memory_blocks[] = {100, 500, 200, 300, 600};
    int block_count = sizeof(memory_blocks) / sizeof(memory_blocks[0]);


    int processes[] = {210, 415, 118, 422};
    int process_count = sizeof(processes) / sizeof(processes[0]);

    int allocation[process_count];
    for (i = 0; i < process_count; i++) {
        allocation[i] = -1;
    }

    for (i = 0; i < process_count; i++) {
        for (j = 0; j < block_count; j++) {
            if (memory_blocks[j] >= processes[i]) {
                allocation[i] = j;
                memory_blocks[j] = -1;
                break;
            }
        }
    }


    printf("First-Fit Allocation Result:\n");
    for (i = 0; i < process_count; i++) {
        if (allocation[i] != -1) {
            int block_size;
            switch (allocation[i]) {
                case 0: block_size = 100; break;
                case 1: block_size = 500; break;
                case 2: block_size = 200; break;
                case 3: block_size = 300; break;
                case 4: block_size = 600; break;
            }
            printf("Process %d -> Block %d\n", processes[i], block_size);
        } else {
            printf("Process %d -> Not allocated\n", processes[i]);
        }
    }

    return 0;
}