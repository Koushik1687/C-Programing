#include <stdio.h> //st 1(compiler reading process)

void sum(); // function no. 1 //st2(compiler reading process)
void sub(); // function no. 2 //st4(compiler reading process)
void mux(); // function no. 3 //st4(compiler reading process)

int main() 
{ // main function, where C program starts to execute......//st6(compiler reading process)
    int inp1, inp2;
    printf("This is a sum function:\n");
    printf("Please enter Numbers 1: ");
    scanf("%d", &inp1);
    printf("Please enter Numbers 2: ");
    scanf("%d", &inp2);
    sum(inp1, inp2); // function calling with values (Pass BY Value)
    sub();           // function calling without values


    printf("Please enter Numbers 1: ");
    scanf("%d", &inp1);
    printf("Please enter Numbers 2: ");
    scanf("%d", &inp2);
    mux(&inp1,&inp2);
    return 0;
}

void sum(int a, int b)
{ // Function -- (pass by value) st3(compiler reading process)
    int sum = a + b;//taking another variable for calculation, which is 'sum' 
    printf("This is Function 1\nSum : %d\n", sum);
}

void sub()
{ // function no. 2 (without values) st5(compiler reading process)

    //int a = 30; // per define value to 'a' variable, variable name is a. We are assiging value 15 to a.
    int shagufta, tiyasha; // shagufta as a && tiyasha as b 
    printf("This is a Substraction function: \n");
    printf("Please enter Numbers 1: ");
    scanf("%d", &shagufta);
    printf("Please enter Numbers 2: ");
    scanf("%d", &tiyasha);
    printf("This is Function 2\nSubstraction of your two number is :  %d\n", shagufta - tiyasha);// inline calculation, without taking another variable 
}

void mux(int *a, int *b){
    printf("This is a Multiplex function: \n");
    printf("\nThis is Function 3\nMultiplex : %d", *a * *b);
}