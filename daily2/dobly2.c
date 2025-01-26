#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *addBeginning(struct node *head, int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return head;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

struct node *addEnding(struct node *head, int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return head;
    }
    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

struct node *addPosition(struct node *head, int value, int position) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        printf("Please Insert Some Data First.\n");
        return head;
    }
    struct node *ptr = head;
    for (int i = 1; i < position - 1; i++) {
        if (ptr->next == NULL) {
            printf("Invalid position.\n");
            return head;
        }
        ptr = ptr->next;
    }
    struct node *ptr2 = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
    temp->next = ptr2;
    if (ptr2 != NULL) {
        ptr2->prev = temp;
    }
    return head;
}

struct node *deleteBeginning(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return head;
    }
    struct node *ptr = head->next;
    free(head);
    head = ptr;
    if (head != NULL) {
        head->prev = NULL;
    }
    return head;
}

struct node *deleteEnding(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    struct node *ptr = head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

struct node *deletePosition(struct node *head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (position == 1) {
        return deleteBeginning(head);
    }
    struct node *ptr = head;
    for (int i = 1; i < position - 1; i++) {
        if (ptr->next == NULL || ptr->next->next == NULL) {
            printf("Invalid position.\n");
            return head;
        }
        ptr = ptr->next;
    }
    struct node *ptr1 = ptr->next->next;
    free(ptr->next);
    ptr->next = ptr1;
    if (ptr1 != NULL) {
        ptr1->prev = ptr;
    }
    return head;
}

void display(struct node *head) {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    while (1) {
        int ch, n, position;
        printf("\nMenu\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Given Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n");
        printf("6. Delete at Given Position\n7. Display\n8. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter Data: ");
            scanf("%d", &n);
            head = addBeginning(head, n);
            break;
        case 2:
            printf("Enter Data: ");
            scanf("%d", &n);
            head = addEnding(head, n);
            break;
        case 3:
            printf("Enter Data: ");
            scanf("%d", &n);
            printf("Enter Position: ");
            scanf("%d", &position);
            head = addPosition(head, n, position);
            break;
        case 4:
            head = deleteBeginning(head);
            break;
        case 5:
            head = deleteEnding(head);
            break;
        case 6:
            printf("Enter Position: ");
            scanf("%d", &position);
            head = deletePosition(head, position);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
