#include <stdio.h>
#include <string.h>
#define max 100

//reverses a string using stack.
char arr[max];
int top =-1;
void push(char a[]){
    int k = strlen(a);
    for (int i = 0; i < k; i++)
    {
        top= top+1; 
        arr[top]=a[i];
    }
    printf("Printing in Stright Order : \n");
    for (int i = 0; i <= top; i++)
    {
        printf("%c\n",arr[i]);
    }
}
void display(){
    printf("Printing in Reverse Order : \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n",arr[i]);
    }
}
int main () {
    char a[max];
    while (1){
        printf("Please enter the element : ");
        scanf("%s",a);
        push(a);
        display();
        break;
    }
}
