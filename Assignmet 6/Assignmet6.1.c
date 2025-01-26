#include <stdio.h>
#include <stdlib.h>
//single link
struct node
{
    int data;
    struct node *next;
};

struct node *inseratbegining(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct node *inseratending(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
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

struct node *inserinbetween(struct node *head, int data, int elementno)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    int i = 0;
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

struct node *deletefrombeginig(struct node *head)
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("The List Is Empty....Please Enter Some Data\n");
    }
    head = head->next;
    free(ptr);
    return head;
}

struct node *deletefromendinig(struct node *head)
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

struct node *deleteinbetween(struct node *head, int elementno)
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

void traversal(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Please Enter Some Data\n");
    }

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = NULL;
    int input, elementno, option;
    while (1)
    {
        printf("Please chose from the below option \n");
        printf("1. Insert From The Begining.\n2. Insert From The Ending.\n3. Insert In Between.\n");
        printf("4. Delete From The Begining.\n5. Delete From The Ending.\n6. Delete In Between.\n");
        printf("7. Display Element\n8. Exit\n");
        printf("Please Enter the option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Please enter Element :");
            scanf("%d", &input);
            head = inseratbegining(head, input);
            break;
        case 2:
            printf("Please enter Element :");
            scanf("%d", &input);
            head = inseratending(head, input);
            break;
        case 3:
            printf("Please enter Place :");
            scanf("%d", &elementno);
            printf("Please enter Element :");
            scanf("%d", &input);
            head = inserinbetween(head, input, elementno);
            break;
        case 4:
            printf("Delete First Element..\n");
            head = deletefrombeginig(head);
            traversal(head);
            break;
        case 5:
            printf("Delete Last Element..\n");
            head = deletefromendinig(head);
            traversal(head);
            break;
        case 6:
            printf("Please enter Place :");
            scanf("%d", &elementno);
            printf("Delete From In Between..\n");
            head = deleteinbetween(head, elementno);
            traversal(head);
            break;
        case 7:
            traversal(head);
            break;
        case 8:
            exit(0);
            break;
        }
    }
    return 0;
}