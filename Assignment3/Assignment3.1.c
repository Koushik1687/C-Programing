#include <stdio.h>
#include <stdlib.h>
#define max 4
//insert, delete and display data of a stack
int stack_arr[max];
int top = -1;

void push(int data)
{
    if (top >= max - 1)
    {
        printf("Overflow...cannot add %d in stack\n", data);
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
    printf("%d >", stack_arr[top]);
    printf("%d\n", top+1);
}


void pop(){
    if (top == -1) {
        printf("Stack Underflow! The stack is empty.\n");
        return;
    }
    printf("Popped %d from the stack.\n", stack_arr[top]);
    top--;
}

void full(){
    if(top == max -1){
        printf("Stack is Full.\n");
        return;
    }
    else{
        printf("Stack is Underflow.\n");
    }
}
void display(){
    if (top == -1) {
        printf("The stack is empty. No items to display.\n");
        return;
    }
    printf("Stack elements (from top to bottom):\n");
    for (int i = top; i >= 0; i--) { 
        printf("%d\n", stack_arr[i]);
    }
}

int main()
{
    int a, option;
    while (1)
    {
        printf("Please Chose the option below :\n1. Push\n2. Pop\n3. Display\n4. Is Full\n5. Exit\nChose :");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Please Enter element you want to Push: ");
            scanf("%d", &a);
            push(a);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            full();
            break;
        case 5:
            exit (0);
        default:
            main();
            break;
        }
    }
    return 0;
}