#include <stdio.h>

int main() {
    int n, i, time = 0, quantum;
    int arrival[20], burst[20], remaining[20];
    int wait[20] = {0}, turnaround[20] = {0};
    int done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while (done < n) {
        int executed = 0;

        for (i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0) {
                if (remaining[i] <= quantum) {
                    time += remaining[i];
                    wait[i] = time - arrival[i] - burst[i];
                    turnaround[i] = time - arrival[i];
                    remaining[i] = 0;
                    done++;
                } else {
                    time += quantum;
                    remaining[i] -= quantum;
                }
                executed = 1;
            }
        }

        // If no process executed, increment time
        if (executed == 0) time++;
    }

    // Output
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], wait[i], turnaround[i]);
    }

    return 0;
}
