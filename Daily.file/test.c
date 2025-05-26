#include <stdio.h>

// void main() {
//     int i = 5, *j, **k;  // Initialize i, j, and k
//     j = &i;  // j is a pointer to i
//     k = &j;  // k is a pointer to j
    
//     // Print addresses
//     printf("%u\n", (void *)&i);   // Address of i
//     printf("%u\n", (void *)j);    // Address j holds, which is address of i
//     printf("%u\n", (void *)*k);   // *k is j, which holds the address of i
//     printf("%u\n", (void *)&j);   // Address of j
//     printf("%u\n", (void *)k);    // Address k holds, which is the address of j
//     printf("%u\n", (void *)&k);   // Address of k

//     // Print values
//     printf("%d\n", i);            // Value of i
//     printf("%d\n", *(&i));        // Value of i (dereferencing &i)
//     printf("%d\n", *j);           // *j gives value of i, since j = &i
//     printf("%d\n", **k);          // **k gives value of i, since k = &j and j = &i
// }



//program 2
// #include<stdio.h>
// int main()
// { 
//  int i;
//  for(i=1;i<=10;i++);
//  {
//    printf("%d",i);
//  }
// } 
// program 3
// #include<stdio.h>
// int main()
// { 
//  int i;
//  for(i=1;i<=200000;i++)
//  {
//    printf("%d\n",i);
//  }
// } 


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
    for (i = 1; i<=n-1; i++) {
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