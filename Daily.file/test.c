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
#include<stdio.h>
int main()
{ 
 int i;
 for(i=1;i<=10;i++);
 {
   printf("%d",i);
 }
} 