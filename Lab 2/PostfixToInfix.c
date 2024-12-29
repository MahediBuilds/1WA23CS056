#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(const char ch);
char pop();
int getPriority(char ch);
char peek();
void infixToPostfix(const char *infix, char *postfix);

int main() {
    char infix[MAX], postfix[MAX];

    fgets(infix, MAX, stdin);

    printf("Infix: %s\n", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
}

void push(const char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int getPriority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else {
        return 0;
    }
}

char peek() {
    return stack[top];
}

void infixToPostfix(const char *infix, char *postfix) {
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        const char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            postfix[j++] = ch;
        } else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (getPriority(ch) <= getPriority(peek())) {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
}
