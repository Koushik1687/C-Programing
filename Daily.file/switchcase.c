#include <stdio.h>

void input();

int main () {
    input();
    return 0;
}

void input(){
    int age=0,i=0;
    printf("Please enter your Age : ");
    scanf("%d",&age);
    if (age <= 17)
    {
        i=1;
    }
    else if (age <=60)
    {
        i=2;
    }
    else if (age >=61)
    {   
        i=3;
    }  
    switch (i)
    {
    case 1:
        printf("You are too young to get your driving licence");
        break;
    case 2:
        printf("You are eligible for driving licence");;
        break;
    case 3:
        printf("You are not allowed");;
        break;
    default:
        break;
    }
}