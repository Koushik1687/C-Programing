#include <stdio.h>
#include <stdlib.h>


struct node 
{
    int data;
    struct node * next;
};


struct node * insert_Beg(struct node * head, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr; 
}


struct node * insert_End(struct node * head, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        ptr->data = data;
        ptr->next = head;
        return ptr;
    }
    else{
        struct node * p = head;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;   
}


struct node * insert_inBet(struct node * head, int data,int elementno){
    struct node * ptr = (struct node *)malloc(sizeof(struct node)); 
    struct node * p= head;
    int i = 0;
    while (i!=elementno-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next=p->next;
    p->next= ptr;
    return head;
}


void traversal(struct node * ptr){
    int count = 0;
    while (ptr != NULL)
    {
        count ++;
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;//
    }
    printf("Number of element : %d\n",count);
}


int main () {
    struct node * head=NULL;
    int a,var,el1;
    while (1){
        printf("\nPlease Choose Your Option Below\n");
        printf("1. Insert At Begening\n2. Insert At Ending\n3. Insert In Between\n");
    // printf("4. Delete From Begening\n5. Delete From Ending\n6. Delete From In Between\n");
        printf("7. Display Element\n8. Exit\nEnter Option :");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            printf("Please Enter The Element : ");
            scanf("%d",&var);
            head = insert_Beg(head,var);
            break;
        case 2:
            printf("Please Enter The Element : ");
            scanf("%d",&var);
            head = insert_End(head,var);
            break;
        case 3:
            printf("Enter The Place ");
            scanf("%d",&el1);
            printf("Please Enter The Element : ");
            scanf("%d",&var);
            head = insert_inBet(head,var,el1);
            traversal(head);
            break;
        case 7:
            traversal(head);
            break;
        default:
            break;
        }
    }
    return 0;
}