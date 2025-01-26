#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *insertBeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct node *insertEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if(head == NULL){
        ptr->data = data;
        ptr->next = head;
        return ptr;
    }

    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

struct node *inserInBet(struct node *head, int data, int elementno)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    int i = 1;
    struct node *p = head;
    while (i != elementno - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}



struct node *deleteBeg(struct node *head)
{

    head = head->next;
    free(head);
    return head;
}
struct node *insertEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if(head == NULL){
        ptr->data = data;
        ptr->next = head;
        return ptr;
    }

    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

struct node *inserInBet(struct node *head, int data, int elementno)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    int i = 1;
    struct node *p = head;
    while (i != elementno - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


void display(struct node *head)
{   int length = 0;
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
        length ++;
    }
    printf("\nLength : %d\n",length);
}

int main()
{
    struct node *head = NULL;
    int data, elementno, input;
    while (1)
    {
        printf("\nInsertion\n1. Begening\n2. Ending\n3. Between");
        printf("\nDeletion\n4. Begening\n5. Ending\n6. Between\n");
        printf("Enter Option : ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("Please Enter Element to Add at begeing :");
            scanf("%d", &data);
            head = insertBeg(head, data);
            display(head);
            break;
        case 2:
            printf("Please Enter Element to Add at Ending :");
            scanf("%d", &data);
            head = insertEnd(head, data);
            display(head);
            break;
        case 3:
            printf("Please Enter Element to add In Between :");
            scanf("%d", &data);
            printf("Please Enter The Position :");
            scanf("%d", &elementno);
            head = inserInBet(head, data, elementno);
            display(head);
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;

        default:
            break;
        }

        if (data == 0)
        {
            exit(0);
        }
    }

    return 0;
}