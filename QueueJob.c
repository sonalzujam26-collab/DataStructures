#include <stdio.h>
#define MAX 5   // maximum number of orders

int queue[MAX];
int front = -1, rear = -1;

// Function to add order
void addOrder() {
    int order;
    if (rear == MAX - 1)
        printf("\nSorry! No more orders can be accepted.\n");
    else {
        if (front == -1)
            front = 0;
        printf("\nEnter order number: ");
        scanf("%d", &order);
        rear++;
        queue[rear] = order;
        printf("Order %d added successfully.\n", order);
    }
}

// Function to serve order
void serveOrder() {
    if (front == -1 || front > rear)
        printf("\nNo orders to serve!\n");
    else {
        printf("\nOrder %d served.\n", queue[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

// Function to display current orders
void displayOrders() {
    int i;
    if (front == -1)
        printf("\nNo pending orders.\n");
    else {
        printf("\nCurrent orders in queue:\n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    printf("\n--- PIZZA PARLOR ORDER SYSTEM ---\n");
    do {
        printf("\n1. Add Order");
        printf("\n2. Serve Order");
        printf("\n3. Display Orders");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addOrder(); break;
            case 2: serveOrder(); break;
            case 3: displayOrders(); break;
            case 4: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}
