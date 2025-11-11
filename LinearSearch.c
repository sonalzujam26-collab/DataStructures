#include <stdio.h>
#include <conio.h>

void main()
{
    int a[100], n, i, key, found = 0;

    clrscr();  // Clears the screen in Turbo C

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers of students:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    // Linear Search
    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            found = 1;
            break;
        }
    }

    if(found == 1)
        printf("Student with roll number %d attended the training program.\n", key);
    else
        printf("Student with roll number %d did NOT attend the training program.\n", key);

    getch();  // Waits for a key press in Turbo C
}
