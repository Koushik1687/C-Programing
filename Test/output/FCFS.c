#include <stdio.h>

int main () {
    int num ;

    printf("Please enter number of process : ");
    scanf("%d",&num);

    int i,s = 1 ,at[num],bt[num],ct[num],wt[num],tat[num];

    printf("Please enter Arrival Time : \n");
    for ( i = 0; i < num; i++)
    {  
        printf("Process %d :",i);
        scanf("%d",&at[i]);
    }

    printf("Please enter Burst Time : \n");
    for ( i = 0; i < num; i++)
    {  
        printf("Process %d :",i);
        scanf("%d",&bt[i]);
    }
    // ct
    for ( i = 0; i < num; i++)
    {
        s = s +bt[i];
        ct[i] = s; 
    }
    // tat
     for ( i = 0; i < num; i++)
     {
        tat[i] = ct[i] - at[i]; 
     }
    //wt
    for ( i = 0; i < num; i++)
    {
        wt[i] = tat[i] - bt[i]; 
    }

    printf("Arrival Burst Complition Turn Arround Waiting Time\n");
    for ( i = 0; i < num; i++)
    {
        printf("%d\t%d\t%d\t\t%d\t\n",at[i],bt[i],ct[i],tat[i]);
    }
    
    return 0;
}