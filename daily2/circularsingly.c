#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* addBeg(struct node* head,int data){
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head ==  NULL){
        head = temp;
        temp->next = head;
        return head;
    }
    else{
       struct node* ptr = head;
       do
       {
            ptr = ptr->next;
       } while (ptr->next!= head);
        temp->next = head;
        ptr->next = temp;
        head = temp; 
        return head;
    }
}
void display(struct node* head){
    struct node* p = head ;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}
int main () {
    struct node* head = NULL;
    head = addBeg(head,30);
    head = addBeg(head,40);
    head = addBeg(head,50);
    head = addBeg(head,60);
    display(head);
    return 0;
}