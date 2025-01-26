#include <stdio.h>
#include <stdlib.h>
#define max 3
//linear queue.
int value[max];
int front = -1;
int rear = -1;
void out();
void in(int data){
    if (rear == max -1){
        printf("Queue is empty");
    }
    else {
        rear ++;
        value[rear] = data;
    }
}
void delete(){
    front ++;
    printf("This will delete %d\n",value[front]);
}
void out(){
    for (int i = front + 1; i <= rear; i++)
    {
        printf("You have entered : %d\n",value[i]);
    } 
}
int main () {
    int a = 0,b;
    while(1){
        printf("Please Chose The Option Below :\n 1. Inset.\n 2. Delete.\n 3. Display.\n 4. Exit.\n Your Option : ");
        scanf("%d",&b);
        switch (b)
        {
        case 1:
            printf("Please enter number you want to insert : ");
            scanf("%d",&a);
            in(a);
            break;
        case 2:
            printf("Deleting Data..");
            delete();
            out();
            break;
        case 3:
            printf("Display :\n");
            out();
            break;
        case 4:
            exit (0);
        default:
            printf("Invalid Option. Try Again....\n");
            main();
        }
    }
    return 0;
}