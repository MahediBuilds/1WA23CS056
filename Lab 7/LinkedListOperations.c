#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node** head) {
    struct Node* i;
    struct Node* j;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *head2;
    }
    *head2 = NULL;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice;

    for (int i = 0; i < 5; i++) {
        insertAtEnd(&list1, rand() % 100);
        insertAtEnd(&list2, rand() % 100);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display List 1\n");
        printf("2. Display List 2\n");
        printf("3. Sort Both Lists\n");
        printf("4. Reverse Both Lists\n");
        printf("5. Concatenate List 2 into List 1\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("List 1: ");
                displayList(list1);
                break;
            case 2:
                printf("List 2: ");
                displayList(list2);
                break;
            case 3:
                sortList(&list1);
                sortList(&list2);
                printf("List 1 sorted: ");
                displayList(list1);
                printf("List 2 sorted: ");
                displayList(list2);
                break;
            case 4:
                reverseList(&list1);
                reverseList(&list2);
                printf("List 1 reversed: ");
                displayList(list1);
                printf("List 2 reversed: ");
                displayList(list2);
                break;
            case 5:
                concatenateLists(&list1, &list2);
                printf("List 2 concatenated into List 1: ");
                displayList(list1);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
