// Q4. Memeory Management: First-Fit Allocation

    
//Team = Koushik Paul - 2421206002040
// Arnab Kamakar - 2421206002011, 
// Tiyasha Biswas - 2422206002006, 
// Chandrima Sarkar - 2422106002015, 
// Soumyodip Mukherjee - 2421206002031, 
// Subhranil Srimani - 2421206002012


#include <stdio.h>

#define BLOCKS 5
#define PROCESSES 4

int main() {
    int memoryBlocks[BLOCKS] = {100, 500, 200, 300, 600};
    int processes[PROCESSES] = {210, 415, 118, 422};
    int allocation[PROCESSES];
    
    for (int i = 0; i < PROCESSES; i++) {
        allocation[i] = -1;
    }
    
    for (int i = 0; i < PROCESSES; i++) {
        for (int j = 0; j < BLOCKS; j++) {
            if (memoryBlocks[j] >= processes[i]) {
                allocation[i] = memoryBlocks[j];
                memoryBlocks[j] = -1;
                break;
            }
        }
    }
    for (int i = 0; i < BLOCKS; i++)
    {
        printf("%d\n", memoryBlocks[i]); 
    }
    
    printf("\n"); 
    printf("Process No.\tProcess Size\tBlock Allocated\n");
    for (int i = 0; i < PROCESSES; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] ); 
        else
            printf("Not Allocated\n");
    }

    return 0;
}
