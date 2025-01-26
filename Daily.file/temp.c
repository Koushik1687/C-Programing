#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};


struct node * add_End(struct node * head,int var)
{
    struct node * temp, *current;
    
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = var;
    temp->next = NULL;

    if (head == NULL){
        head = temp;
    }
    else {
    current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
    
    return head;
};
struct node * add_Beg(struct node * head,int var)
{
    struct node * temp;
    
    temp = (struct node *) malloc(sizeof(struct node));
    
    temp->data = var;
    temp->next = NULL;

    if (head == NULL){
        head = temp;
    }
    return temp;

};
void display(struct node * head){
    struct node * temp=head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp!= NULL){
        printf("Elemet : %d",temp->data);
            temp = temp->next;
        }
}
int main (){
    struct node * head = NULL;
    int input,data;
    while (1)
    {
        printf("Please Enter The Option Below : \n1. Insert At Begining\n2. Insert At End\n3. Insert In Between");
        printf("\n4. Delete At Begining\n5. Delete At End\n6. Delete In Between\n7. Exit\nPlease Enter :");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            printf("Please Enter Element to Insert At Begining : ");
            scanf("%d",&data);
            head = add_End(head,data);
            break;
        case 2:
            printf("Please Enter Element to Insert At Ending : ");
            scanf("%d",&data);
            head = add_Beg(head,data);
            break;
        // case 3:
        //     printf("Please Enter Element to Insert In Between : ");
        //     scanf("%d",&data);
        //     head = add_End(head,data);
        //     break;
        // case 4:
        //     printf("Please Enter The Element To Delete From Begining : ");
        //     scanf("%d",&data);
        //     head = add_End(head,data);
        //     break;
        // case 5:
        //     printf("Please Enter The Element To Delete From Ending : ");
        //     scanf("%d",&data);
        //     head = add_End(head,data);
        //     break;
        // case 6:
        //     printf("Please Enter Element to Insert At Begining : ");
        //     scanf("%d",&data);
        //     head = add_End(head,data);
        //     break;
        case 7:
            display(head);
            printf("Exiting From The Program !!\n Thank You !!");
            exit(0);
        default:
            break;
        }
    }
}