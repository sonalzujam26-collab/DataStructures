#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Function to push an element onto the stack
void push() {
    int val;
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMemory not available! Stack Overflow.\n");
        return;
    }

    printf("\nEnter value to push: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = top;
    top = newNode;

    printf("Element %d pushed successfully.\n", val);
}

// Function to pop an element from the stack
void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("\nStack Underflow! No element to pop.\n");
        return;
    }

    temp = top;
    printf("\nElement %d popped successfully.\n", top->data);
    top = top->next;
    free(temp);
}

// Function to display stack elements
void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nStack elements are:\n");
    temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void main() {
    int choice;
    clrscr(); // Clears the Turbo C screen

    do {
        printf("\n====== STACK OPERATIONS (Linked List) ======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 4);

    getch(); // Wait for user input before closing
}
