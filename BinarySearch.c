#include <stdio.h>

void binarySearch(int arr[], int n, int key);

void main()
{
    int n, i, key;
    int roll[50];

    clrscr(); // Clear screen (Turbo C specific)

    printf("Enter number of students who attended the training program: ");
    scanf("%d", &n);

    printf("Enter roll numbers of students in random order:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &roll[i]);
    }

    // Sorting array (Binary Search needs sorted array)
    for(i = 0; i < n - 1; i++)
    {
        int j, temp;
        for(j = i + 1; j < n; j++)
        {
            if(roll[i] > roll[j])
            {
                temp = roll[i];
                roll[i] = roll[j];
                roll[j] = temp;
            }
        }
    }

    printf("\nEnter roll number to search: ");
    scanf("%d", &key);

    binarySearch(roll, n, key);

    getch(); // Wait for key press (Turbo C specific)
}

void binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid, found = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            printf("\nRoll number %d attended the training program.", key);
            found = 1;
            break;
        }
        else if(arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(!found)
        printf("\nRoll number %d did NOT attend the training program.", key);
}
