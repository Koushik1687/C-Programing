#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *insertAtBeg(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    return head;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *prt = head;
        while (prt->next != NULL)
        {
            prt = prt->next;
        }
        prt->next = temp;
        temp->prev = prt;
    }
    return head;
}
struct node *insertAtPosition(struct node *head, int data, int position)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    struct node *prt = head;
    if (position == 1)
    {
        prt = prt->next;
        position--;
    }
    struct node *prt2 = prt->next;

    prt->next = temp;
    temp->prev = prt;
    temp->next = prt2;
    return head;
}
struct node *deleteBeginning(struct node *head)
{
    struct node *prt = head;
    if (prt == NULL)
    {
        printf("The List Is Empty....Please Enter Some Data\n");
        return head;
    }
    else
    {
        prt = head->next;
        free(head);
        head = prt;
        return head;
    }
}

struct node *deleteEnd(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

struct node *deleteAtPosition(struct node *head, int elementno)
{
    struct node *p = head, *q;
    int i = 0;
    while (i != elementno - 2)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return p;
}
void display(struct node *head)
{
    printf("Your Linked List:\n");
    struct node *disp = head;
    while (disp != NULL)
    {
        printf("%d ", disp->data);
        disp = disp->next;
    }
    printf("\n");
}
int main()
{
    struct node *head = NULL;
    while (1)
    {
        int ch, n, position = 0;
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Given Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n");
        printf("6. Delete at Given Position\n7. Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d", &n);
            head = insertAtBeg(head, n);
            // display(head);
            break;
        case 2:
            printf("Enter Data: ");
            scanf("%d", &n);
            head = insertAtEnd(head, n);
            // display(head);
            break;
        case 3:
            printf("Enter Data: ");
            scanf("%d", &n);
            printf("Enter position: ");
            scanf("%d", &position);
            head = insertAtPosition(head, n, position);
            break;
        case 4:
            head = deleteBeginning(head);
            break;
        case 5:
            deleteEnd(head);
            break;
        case 6:
            printf("Please enter Place :");
            scanf("%d", &position);
            head = deleteAtPosition(head,position);
            break;
        case 7:
            display(head);
        case 8:
            head = NULL;
        }
    }
    return 0;
}