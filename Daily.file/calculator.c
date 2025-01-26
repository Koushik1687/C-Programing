#include <stdio.h>
#include <stdlib.h>

void add(int a,int b){
    printf("SUM : %d\n", a+b);
}
void sub(int a,int b){
    printf("Subtraction : %d\n", a-b);
}
void mux(int a,int b){

    printf("Multiplication : %d\n", a*b);
}

void division(float c, float d) {
    if (d != 0)
        printf("Division : %.2f\n", c / d);
    else
        printf("Error: Division by zero is not allowed.\n");
}

int main (){
    
    int a, in1, in2;
    float in3, in4;
    
    while(1)
    {
        printf("\nPlease choose the option below\n");
        printf("\n 1. Add\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Exit\n");
        printf("\nPlease enter your option : ");
        scanf("%d",&a);
        switch (a) {
            case 1:
                printf("Please Enter Two Numbers: ");
                scanf("%d %d", &in1, &in2);
                add(in1, in2);
                break;
            case 2:
                printf("Please Enter Two Numbers: ");
                scanf("%d %d", &in1, &in2);
                sub(in1, in2);
                break;
            case 3:
                printf("Please Enter Two Numbers: ");
                scanf("%d %d", &in1, &in2);
                mux(in1, in2);
                break;
            case 4:
                printf("Please Enter Two Numbers: ");
                scanf("%f %f", &in3, &in4);
                division(in3, in4);
                break;
            case 5:
                printf("Exiting program. Good Bye!\n");
                exit(0);
            default:{
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
}