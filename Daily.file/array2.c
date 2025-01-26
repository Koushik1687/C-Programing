#include <stdio.h>

int main () {

    int age;
    printf("Please enter your age : \n");
    scanf("%d", &age);
    switch (age)
    {
    case 18:
        printf("Your are adult");
        break;
    default:
        printf("Your are kid");
        break;
    }
    return 0;
}