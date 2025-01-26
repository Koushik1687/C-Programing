#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *link)
{
    while (link != NULL)
    {
        printf("Element : %d\n", link->data);
        link = link->next;
    }
}

int main()
{
    struct node *first, *second, *third, *fourth;
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    first->data = 30;
    first->next = second;

    second->data = 40;
    second->next = third;

    third->data = 50;
    third->next = fourth;

    fourth->data = 80;
    fourth->next = NULL;
    
    display(first);

    free(first);
    free(second);
    free(third);
    free(fourth);
    return 0;
}