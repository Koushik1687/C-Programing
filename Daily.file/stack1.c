#include <stdio.h>
#include <stdlib.h>
#define max 4

int top = -1;
int arr[max];

void push(int data ){
    if (top >= max)
    {
        printf("Overflow...cannot add %d in stack\n", data);
        return;
    }
    top = top + 1;
    arr[top] = data;
    printf("%d>>>%d\n",top,arr[top]);
}
void pop(){
    if (top = -1){
        printf("Please insert some data.\n");
        return;
    }
    printf("%d is deleted...\n",arr[top]);
    top = top -1;
}
void display(){
    for (int i = top; i >= 0; i--)
    {
        printf(">>>%d\n",arr[i]);
    }
}

int main () {
    int data,option;
    while (1){
        printf("Please Chose the option below :\n1. Push\n2. Pop\n3. Display\n4. Is Full\n5. Exit\nChose :");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Please Enter element you want to Push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            // full();
            break;
        case 5:
            exit (0);
        default:
            main();
            break;
        }
    }
    // push(90);
    // push(70);
    // push(80);
    // push(40);

    // printf("\n");
    // pop();
    // printf("\n");
    // display();

    return 0;
}