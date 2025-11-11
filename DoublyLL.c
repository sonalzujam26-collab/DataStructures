#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void create();
void insert_start();
void insert_end();
void insert_between();
void delete_start();
void delete_end();
void delete_between();
void display();

void main() {
    int choice;
    clrscr();

    while(1) {
        printf("\n========= DOUBLY LINKED LIST MENU =========\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Start\n");
        printf("3. Insert at End\n");
        printf("4. Insert Between\n");
        printf("5. Delete at Start\n");
        printf("6. Delete at End\n");
        printf("7. Delete Between\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create(); break;
            case 2: insert_start(); break;
            case 3: insert_end(); break;
            case 4: insert_between(); break;
            case 5: delete_start(); break;
            case 6: delete_end(); break;
            case 7: delete_between(); break;
            case 8: display(); break;
            case 9: exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }
}

// Create doubly linked list
void create() {
    struct node *newnode, *temp;
    int n, i;
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if(start == NULL)
            start = newnode;
        else {
            temp = start;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
    printf("\nDoubly Linked List Created Successfully.\n");
}

// Insert at start
void insert_start() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert at start: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = start;

    if(start != NULL)
        start->prev = newnode;
    start = newnode;

    printf("\nNode inserted at start.\n");
}

// Insert at end
void insert_end() {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert at end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(start == NULL) {
        newnode->prev = NULL;
        start = newnode;
    } else {
        temp = start;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("\nNode inserted at end.\n");
}

// Insert between nodes
void insert_between() {
    struct node *newnode, *temp;
    int pos, i;
    printf("\nEnter position after which to insert: ");
    scanf("%d", &pos);

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    temp = start;
    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
        printf("\nPosition not found!\n");
    else {
        newnode->next = temp->next;
        newnode->prev = temp;

        if(temp->next != NULL)
            temp->next->prev = newnode;

        temp->next = newnode;
        printf("\nNode inserted after position %d.\n", pos);
    }
}

// Delete at start
void delete_start() {
    struct node *temp;
    if(start == NULL)
        printf("\nList is empty!\n");
    else {
        temp = start;
        start = start->next;
        if(start != NULL)
            start->prev = NULL;
        free(temp);
        printf("\nNode deleted from start.\n");
    }
}

// Delete at end
void delete_end() {
    struct node *temp;
    if(start == NULL)
        printf("\nList is empty!\n");
    else if(start->next == NULL) {
        free(start);
        start = NULL;
        printf("\nLast node deleted.\n");
    } else {
        temp = start;
        while(temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
        printf("\nNode deleted from end.\n");
    }
}

// Delete between nodes
void delete_between() {
    struct node *temp;
    int pos, i;

    if(start == NULL)
        printf("\nList is empty!\n");
    else {
        printf("\nEnter position to delete: ");
        scanf("%d", &pos);
        temp = start;

        for(i = 1; i < pos && temp != NULL; i++)
            temp = temp->next;

        if(temp == NULL)
            printf("\nPosition not found!\n");
        else if(temp == start)
            delete_start();
        else if(temp->next == NULL)
            delete_end();
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            printf("\nNode deleted from position %d.\n", pos);
        }
    }
}

// Display all nodes (forward direction)
void display() {
    struct node *temp;
    if(start == NULL)
        printf("\nList is empty!\n");
    else {
        printf("\nDoubly Linked List (Forward): ");
        temp = start;
        while(temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
