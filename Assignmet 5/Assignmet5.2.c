#include <stdio.h>
#include <stdlib.h>
#define max 5
//reverse the elements of an array.
int arr[max];
int top =-1;
void display(){
    printf("Array Reverse\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d",arr[i]);
    }
}
void insert(int ar[]){
for (int i = 0; i < max; i++)
    {
        top = top +1;
        arr[top]=ar[i];
    }
    display();
}
int main () {
    int ar[max];
    for (int i = 0; i < max; i++)
    {
        printf("Please enter %d element :",i);
        scanf("%d", &ar[i]);
    } 
        insert(ar);
    return 0;
}