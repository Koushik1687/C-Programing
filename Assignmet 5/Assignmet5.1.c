#include <stdio.h>
#define MAX 5
//de-queue
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Dequeue;

void initDequeue(Dequeue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Dequeue *dq) {
    return dq->front == -1;
}

int isFull(Dequeue *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->rear + 1 == dq->front);
}

void insertFront(Dequeue *dq, int value) {
    if (isFull(dq)) {
        printf("Dequeue is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->data[dq->front] = value;
    printf("Inserted at front: %d\n", value);
}

void insertRear(Dequeue *dq, int value) {
    if (isFull(dq)) {
        printf("Dequeue is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->data[dq->rear] = value;
    printf("Inserted at rear: %d\n", value);
}

void deleteFront(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty!\n");
        return;
    }
    printf("Deleted from front: %d\n", dq->data[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void deleteRear(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty!\n");
        return;
    }
    printf("Deleted from rear: %d\n", dq->data[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

void display(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty!\n");
        return;
    }
    printf("Dequeue elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->data[i]);
        if (i == dq->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Dequeue dq;
    initDequeue(&dq);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;

            case 3:
                deleteFront(&dq);
                break;

            case 4:
                deleteRear(&dq);
                break;

            case 5:
                display(&dq);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
