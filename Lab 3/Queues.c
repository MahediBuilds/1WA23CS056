#include <stdio.h>

#define MAX 3

int queue[MAX];

void enqueue(int* front, int* rear);
void dequeue(int* front, int* rear);
void display(int* front, int* rear);

int main(void) {
    int front = -1;
    int rear = -1;
    int choice;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue(&front, &rear);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(&front, &rear);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}

void enqueue(int* front, int* rear) {
    if (*rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (*front == -1) {
        *front = 0;
    }

    int item;
    printf("Enter the value: ");
    scanf("%d", &item);

    queue[++(*rear)] = item;
}

void dequeue(int* front, int* rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Dequeued: %d\n", queue[*front]);
    (*front)++;
}

void display(int* front, int* rear) {
    if (*front == -1 || *front > *rear) {
        printf("Empty queue\n");
        return;
    }

    printf("Queue: ");
    for (int i = *front; i <= *rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
