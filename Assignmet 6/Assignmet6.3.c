#include <stdio.h>
#include <stdlib.h>
//circular link
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        printf("Inserted %d as the first node.\n", data);
        return;
    }

    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
    printf("Inserted %d at the end.\n", data);
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 1) {
        if (*head == NULL) {
            *head = newNode;
            newNode->next = *head;
        } else {
            Node* temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            newNode->next = *head;
            temp->next = newNode;
            *head = newNode;
        }
        printf("Inserted %d at position 1.\n", data);
        return;
    }

    Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    if (temp->next == *head && position != 2) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, position);
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;

    if (position == 1) {
        if (temp->next == *head) {
            printf("Deleted node with data %d from position 1.\n", temp->data);
            free(temp);
            *head = NULL;
        } else {
            while (temp->next != *head) {
                temp = temp->next;
            }
            Node* delNode = *head;
            temp->next = (*head)->next;
            *head = (*head)->next;
            printf("Deleted node with data %d from position 1.\n", delNode->data);
            free(delNode);
        }
        return;
    }

    Node* prev = NULL;
    for (int i = 1; i < position && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head && position != 2) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted node with data %d from position %d.\n", temp->data, position);
    free(temp);
}

void traverse(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Position\n");
        printf("3. Delete at Position\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 4:
                traverse(head);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}