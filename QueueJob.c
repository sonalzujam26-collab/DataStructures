#include <stdio.h>
#include <conio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to add a job (enqueue)
void addJob(int job) {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot add more jobs.");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = job;
        printf("\nJob %d added to the queue.", job);
    }
}

// Function to delete a job (dequeue)
void deleteJob() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No jobs to delete.");
    } else {
        printf("\nJob %d deleted from the queue.", queue[front]);
        front++;
    }
}

// Function to display all jobs in the queue
void displayQueue() {
    int i;
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.");
    } else {
        printf("\nCurrent Jobs in Queue:\n");
        for (i = front; i <= rear; i++) {
            printf("Job %d\n", queue[i]);
        }
    }
}

void main() {
    int choice, job;
    clrscr();

    while (1) {
        printf("\n\n--- Job Queue Menu ---");
        printf("\n1. Add Job");
        printf("\n2. Delete Job");
        printf("\n3. Display Jobs");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter job number to add: ");
                scanf("%d", &job);
                addJob(job);
                break;

            case 2:
                deleteJob();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("\nExiting program...");
                getch();
                return;

            default:
                printf("\nInvalid choice! Try again.");
        }
    }
}
