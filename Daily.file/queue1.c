#include <stdio.h>
#include <stdlib.h>
#define max 2
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
        printf("delete %d\n",value[front]);

}
void out(){
    for (int i = front + 1; i <= rear; i++)
    {
        printf("\n\ndisplay : %d\n",value[i]);
    }
    
}
int main () {
    int a = 0;
    while(1){
        printf("enter : ");
        scanf("%d",&a);
        in(a);
        printf("enter : ");
        scanf("%d",&a);
        in(a);
        out();
        delete();
        out();
        break;
    }
    
    
    return 0;
}