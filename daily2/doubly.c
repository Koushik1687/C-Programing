#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *insertBeg(struct node *head, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    return head;
}
struct node *insertEnd(struct node *head, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
    return head;
}
struct node *insertPosition(struct node *head, int data, int poisition)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        printf("List is Empty");
        return head;
    }
    else
    {
        struct node *ptr = head;
        struct node *ptr1;
        while (poisition-1 >1)
        {
            ptr = ptr->next;
            poisition --;
        }
        ptr1 = ptr->next;
        ptr->next = newnode;
        newnode->prev = ptr;
        newnode->next = ptr1;
    }
    return head;
}
struct node *deleteBeg(struct node *head)
{
    if (head == NULL){
        printf("The list is Empty");
        return 0;
    }
    else if(head->next == NULL){
        free(head);
        return 0;
    }else{
        struct node *ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
    }
    return head;
}
struct node *deletePosition(struct node *head,int positon)
{
     if (head == NULL)
    {
        printf("List is Empty");
        return head;
    }
    else
    {
        struct node *ptr = head;
        struct node *ptr1;
        while (positon-1 >1)
        {
            ptr = ptr->next;
            positon --;
        }
        ptr1 = ptr->next->next;
        free(ptr->next);
        ptr1->prev= ptr;
        ptr->next = ptr1; 
    }
    return head;
}
struct node *deleteEnd(struct node *head)
{
    if (head->next == NULL){
        free(head);
        head = NULL;
        return 0;
    }
    else{
        struct node *ptr = head;
        while (ptr->next->next != NULL){
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
        return head;
    }
}
void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head = NULL;
    head = insertBeg(head, 30);
    head = insertBeg(head, 40);
    head = insertEnd(head, 70);
    head = insertPosition(head, 50,2);
    display(head);
    printf("\n");
    head = insertPosition(head, 60,2);
    display(head);
    printf("\n");
    head = insertPosition(head, 90,3);
    display(head);
    printf("\n");
    head = insertBeg(head, 10);
    display(head);
    printf("\n");
    head = deleteEnd(head);
    display(head);
    printf("\n");
    head = deleteBeg(head);
    display(head);
    printf("\n");
    head = deletePosition(head,2);
    display(head);
    printf("\n");
    head = insertBeg(head, 33);
    head = insertEnd(head, 77);
    head = insertPosition(head, 80,3);
    display(head);
    printf("\n");
    head = deleteEnd(head);
    head = deleteBeg(head);
    display(head);
    printf("\n");
    head = deleteEnd(head);
    head = deleteEnd(head);
    head = deleteEnd(head);
    head = deleteEnd(head);
    head = deleteBeg(head);
    display(head);
    printf("\n");

    return 0;
}