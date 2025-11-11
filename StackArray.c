#include <stdio.h>
#include <conio.h>
#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element into the stack
void push() {
    int val;
    if (top == MAX - 1)
        printf("\nStack Overflow! Cannot push element.\n");
    else {
        printf("\nEnter value to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
        printf("Element %d pushed successfully.\n", val);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1)
        printf("\nStack Underflow! No element to pop.\n");
    else {
        printf("\nElement %d popped successfully.\n", stack[top]);
        top--;
    }
}

// Function to display stack elements
void display() {
    int i;
    if (top == -1)
        printf("\nStack is empty.\n");
    else {
        printf("\nStack elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void main() {
    int choice;
    clrscr(); // Clears the Turbo C screen
    do {
        printf("\n====== STACK OPERATIONS ======\n");
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
