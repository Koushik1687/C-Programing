#include <stdio.h>
void sum(); // fun difine
    void sub(); // fun difine
    void mux(); // fun difine
    void div(); // fun difine
    int main()
    {
        int input;
        printf("This is a Calculator Function using Switch Case");
        while (1) // making a infinite loop to run the below option until user chose to exit
        {
            printf("Please chose the below option you want to perform:\n1. Sum\n2. Substraction\n3. Multiplication\n4. Division\n5. Exit\nChose option :"); // creating a menu for the user
            scanf("%d", &input);
            switch (input)
            {
            case 1: // case 1 if user wants to add two numbers
                sum();
                break;
            case 2: // case 2 if user wants to Substract two numbers
                sub();
                break;
            case 3: // case 1 if user wants to Multiplication two numbers
                mux();
                break;
            case 4: // case 1 if user wants to Division two numbers
                div();
                break;
            case 5: // case 1 if user wants exit
                exit(0);
                break;
            default:
                printf("You chose the wrong option !!, Please try again\n"); // making a default case if user chose a wrong option
                break;
            }
        }
        return 0;
    }

    void sum()
    { // fun declaration
        int a, b;
        printf("This is a Sum Function.\n");
        printf("Please enter number 1 : \n");
    scanf("%d", &a);
    printf("Please enter number 2 : \n");
    scanf("%d", &b);
    printf("Your Sum is %d + %d = %d\n", a, b, a + b);
}

void sub()
{ // fun declaration
    int a, b;
    printf("This is a Substraction Function.\n");
    printf("Please enter number 1 : \n");
    scanf("%d", &a);
    printf("Please enter number 2 : \n");
    scanf("%d", &b);
    printf("Your Substraction is %d - %d = %d\n", a, b, a - b);
}

void mux()
{ // fun declaration
    int a, b;
    printf("This is a Multiplication Function.\n");
    printf("Please enter number 1 : \n");
    scanf("%d", &a);
    printf("Please enter number 2 : \n");
    scanf("%d", &b);
    printf("Your Multiplication is %d * %d = %d\n", a, b, a * b);
}

void div()
{ // fun declaration
    float a, b; // taking float value beacue we are dividing two numbers it can give a float value in return.
    printf("This is a Division Function.\n");
    printf("Please enter number 1 : \n");
    scanf("%f", &a);
    printf("Please enter number 2 : \n");
    scanf("%f", &b);
    printf("Your Division is %f / %f = %0.2f\n", a, b, a / b); // 0.2f means only print two number after point(.) for ex 2.30
}