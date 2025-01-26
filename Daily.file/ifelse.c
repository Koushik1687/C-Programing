#include <stdio.h>

void input();

int main () {
    input();
    return 0;
}

void input(){
    int age=0;
    printf("Please enter your Age : ");
    scanf("%d",&age);
    if (age <= 17)
    {
        printf("You are too young to get your driving licence");
    }
    else if (age <=60)
    {
        printf("You are eligible for driving licence");
    }
    else if (age >=61)
    {
        printf("You are not allowed");
    }  
}