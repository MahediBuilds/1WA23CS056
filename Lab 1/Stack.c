#include <stdio.h>
#include <stdlib.h>

#define MAX 3

char stack[MAX];
int top = -1;

void push(char);
char pop();
void display();

int main(void) {
    char choice, value;

    printf("Welcome to Stack Operations\n");
    while (1) {

        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);  

        if (choice == '1') {
            printf("Enter the value : ");
            scanf(" %c", &value);  
            push(value);

        } else if (choice == '2') {
            pop();

        } else if (choice == '3') {
            display();

        } else if (choice == '4') {
            exit(0);
        } else {
            printf("Invalid choice\n");
        }
    }
}

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;

    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;

    } else {
        return stack[top--];
    }
}

void display() {
    if (top == -1) {
        printf("Stack Empty\n\n");
        return;

    } else {
        printf("Stack : ");
        for (int i = top; i >= 0; i--) {
            printf("%c ", stack[i]);
        }
        printf("\n");
    }
}