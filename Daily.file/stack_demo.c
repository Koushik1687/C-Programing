#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int data) {
    if (top >= MAX - 1) { // Check overflow condition before incrementing `top`
        printf("Stack Overflow! Cannot push %d.\n", data);
        return;
    }
    top++;
    stack_arr[top] = data;
    printf("Pushed %d at position %d.\n", data, top);
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) { // Check underflow condition
        printf("Stack Underflow! The stack is empty.\n");
        return -1;
    }
    int popped = stack_arr[top];
    top--;
    printf("Popped %d from position %d.\n", popped, top + 1);
    return popped;
}

int main() {
    int choice, data;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
