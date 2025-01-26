#include <stdio.h>
#include <stdlib.h>
#define size 5

int ch;
int q[size];
int rear = -1;
int front = -1;

void Insert_queue();
void Delete_queue();
void Display_queue();
void Insert_queue()
{
    if (rear == size - 1)
    {
        printf("\n Queue is overflow");
    }
    else
    {
        printf("\n Input the element :");
        scanf("%d", &ch);
        rear++;
        q[rear] = ch;
    }
}
void Delete_queue()
{
    if (front == rear)
    {
        printf("\n Underflow");
    }
    else
    {
        front++;
        ch = q[front];
        printf("\n Element deleted : %d", ch);
    }
}
void Display_queue() // char q[])
{
    int i;
    if (front == rear)
    {
        printf("\n Underflow");
    }
    else
    {
        for (i = front + 1; i <= rear; i++)
            printf(" %d ", q[i]);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\nInsert->1 \nDelete->2 \nDisplay->3 \nQuit-.4:");
        printf("\nInput the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Insert_queue();
            break;
        case 2:
            Delete_queue();
            break;
        case 3:
            Display_queue();
            break;

        case 4:
            exit(0);
        }
    }
}
