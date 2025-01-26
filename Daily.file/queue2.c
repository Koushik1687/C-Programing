#include <stdio.h>
#define max 5
int front = -1;
int rear = -1;
int arr[max];
void push(int input)
{
    if (rear == max - 1)
    {
        printf("Queue is Full.\n");
    }
    else
    {
        rear++;
        arr[rear] = input;
    }
}
void pop()
{
    if (front == rear)
    {
        printf("The Queue is Empty.Please delete some item.\n");
    }
    else
    {
        front++;
        printf("%d\n",front);
        printf("%d this elemet is deleted.\n", arr[front]);
    }
}
void display()
{
    if (front == rear)
    {
        printf("The Queue is Empty.Please insert some item.\n");
    }
    else
    {
        printf("Displaying Data.\n");
        for (int i = front =1; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}
int main()
{
    int a, b;
    while (1)
    {
        printf("\nMenu\n1. Insert\n2. Delete\n3. Display\nEnter : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Insert : ");
            scanf("%d", &b);
            push(b);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    }
    return 0;
}
