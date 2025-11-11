#include <stdio.h>
#include <conio.h>

// Function for Linear Search
void search(int a[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            printf("Student with roll number %d attended the training program.\n", key);
            return;   // Exit the function after finding
        }
    }

    // If not found in loop
    printf("Student with roll number %d did NOT attend the training program.\n", key);
}

void main()
{
    int a[50], n, key, i;

    clrscr();  // Clears screen (Turbo C)

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers of students:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    // Call search function
    search(a, n, key);

    getch();  // Waits for a key press
}
