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
    int a[5] = {100, 500, 200, 300, 600};
    int b[4] = {210, 415, 118, 422};
    int c[4];
    int d[5];

    for (int i = 0; i < 4; i++) {
        d[i] = -1;
    }


    for (int i = 0; i <=10; i++)
    {
        printf("%d\n",d[i]); 
    }
    
    return 0;
}
