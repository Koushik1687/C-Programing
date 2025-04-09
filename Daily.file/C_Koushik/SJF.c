#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0,i,j;

    // Input burst times for all processes
    for (i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Sorting the processes based on burst time (Shortest Job First)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst_time[i] > burst_time[j]) {
                // Swap burst times
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    waiting_time[0] = 0; // The first process has no waiting time
    for ( i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for( j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j]; // Waiting time is sum of all previous burst times
        }
    }

    // Calculate turnaround time
    for ( i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i]; // Turnaround time = waiting time + burst time
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Output the results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    // Calculate and display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    return 0;
}

