#include <stdio.h>
#include <limits.h>
#include <stdlib.h> 

#define MAX_PROCESSES 100 // Adjust this if needed

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortProcesses(int processes[MAX_PROCESSES][5], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[j][1] < processes[i][1] || 
               (processes[j][1] == processes[i][1] && processes[j][2] < processes[i][2])) {
                for (int k = 0; k < 5; k++) {
                    swap(&processes[i][k], &processes[j][k]);
                }
            }
        }
    }
}

void calculateTimes(int processes[][5], int n) {
    int completed = 0, currentTime = 0;

    // ? Allocate memory dynamically to avoid "constant value" error
    int *isCompleted = (int *)calloc(n, sizeof(int));

    while (completed < n) {
        int shortestIndex = -1, shortestBT = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i][1] <= currentTime && !isCompleted[i] && processes[i][2] < shortestBT) {
                shortestBT = processes[i][2];
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1) {
            currentTime++;
        } else {
            processes[shortestIndex][3] = currentTime - processes[shortestIndex][1];
            processes[shortestIndex][4] = processes[shortestIndex][3] + processes[shortestIndex][2];
            currentTime += processes[shortestIndex][2];
            isCompleted[shortestIndex] = 1;
            completed++;
        }
    }

    // ? Free dynamically allocated memory
    free(isCompleted);
}

void displayResults(int processes[MAX_PROCESSES][5], int n, float avgWT, float avgTAT) {
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", processes[i][0], processes[i][1], processes[i][2], processes[i][3], processes[i][4]);
    }
    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);
}

int main() {
    int n;
    printf("SJF \n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Error: Too many processes (max %d allowed)\n", MAX_PROCESSES);
        return 1;
    }

    int processes[MAX_PROCESSES][5];

    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d (AT BT): ", i + 1);
        scanf("%d %d", &processes[i][1], &processes[i][2]);
        processes[i][0] = i + 1;
    }

    sortProcesses(processes, n);
    calculateTimes(processes, n);

    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        totalWT += processes[i][3];
        totalTAT += processes[i][4];
    }
    float avgWT = totalWT / n;
    float avgTAT = totalTAT / n;

    displayResults(processes, n, avgWT, avgTAT);
    return 0;
}

