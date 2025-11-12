#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create the first list
void createList() {
    int n, i, value;
    struct node *newNode, *temp;

    printf("\nEnter number of nodes to create: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    printf("\nLinked list created successfully.\n");
}

// Function to add a new node at the end
void addNode() {
    int value;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to add: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Node added successfully.\n");
}

// Function to display all nodes
void displayList() {
    struct node *temp;

    if (head == NULL)
        printf("\nList is empty.\n");
    else {
        printf("\nLinked list elements are:\n");
        temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function with menu
int main() {
    int choice;
    printf("\n--- SINGLY LINKED LIST OPERATIONS ---\n");

    do {
        printf("\n1. Create List");
        printf("\n2. Add Node");
        printf("\n3. Display List");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: addNode(); break;
            case 3: displayList(); break;
            case 4: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
