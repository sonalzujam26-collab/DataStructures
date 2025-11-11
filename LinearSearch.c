#include <stdio.h>

#define MAX 100   // maximum number of students

// Function declaration
int linearSearch(int arr[], int n, int key);

void main()
{
    int rollNo[MAX], n, i, key, found;

    clrscr();  // clear the screen (Turbo C specific)

    printf("Enter total number of students who attended the training program: ");
    scanf("%d", &n);

    printf("\nEnter roll numbers of students in random order:\n");
    for(i = 0; i < n; i++)
    {
        printf("Roll No %d: ", i + 1);
        scanf("%d", &rollNo[i]);
    }

    printf("\nEnter the roll number to search: ");
    scanf("%d", &key);

    // call linear search function
    found = linearSearch(rollNo, n, key);

    if(found == -1)
        printf("\nStudent with roll number %d did NOT attend the training program.", key);
    else
        printf("\nStudent with roll number %d attended the training program (found at position %d).", key, found + 1);

    getch();  // to hold screen in Turbo C
}

// Function definition
int linearSearch(int arr[], int n, int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;   // return index if found
    }
    return -1;   // return -1 if not found
}
