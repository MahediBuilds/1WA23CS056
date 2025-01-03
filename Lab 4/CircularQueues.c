#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n\n");
        return;
    }
    if (front == -1) { 
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Inserted %d\n", value);
    printf("\n");
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("\n");
}

void display() {
    if (front == -1) {
        printf("Queue Empty\n\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
