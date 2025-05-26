#include <stdio.h>

int main() {
    int n, bt[5], wt[5], ct[5], tat[5], at[5];
    int i, s = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process arrival time:\n");
    for (i = 0; i < n; i++) {
        printf("Enter time: ");
        scanf("%d", &at[i]);
    }

    printf("Enter process burst time:\n");
    for (i = 0; i < n; i++) {
        printf("Enter time: ");
        scanf("%d", &bt[i]);
    }

    // Completion time calculation
    s = at[0]+bt[0];
    ct[0] = s;
    for (i = 1; i<= n-1; i++) {
        s = s + bt[i];
        ct[i] = s;
    }

    // Turnaround time = Completion time - Arrival time
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
    }

    // Waiting time = Turnaround time - Burst time
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }

    // Output table
    printf("\nProcess Arrival Time:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", at[i]);
    }

    printf("\nProcess Completion Time:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", ct[i]);
    }

    printf("\nProcess Waiting Time:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", wt[i]);
    }

    printf("\nProcess Turnaround Time:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", tat[i]);
    }

}