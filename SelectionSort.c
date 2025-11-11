#include <stdio.h>

void selectionSort(float arr[], int n) {
    int i, j, minIndex;
    float temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the elements
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    float percent[100];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter percentage of %d students:\n", n);
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &percent[i]);
    }

    selectionSort(percent, n);

    printf("\nPercentages in Ascending Order:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\t", percent[i]);
    }

    printf("\n\nTop 5 Scores:\n");
    for (i = n - 1; i >= n - 5 && i >= 0; i--) {
        printf("%.2f\t", percent[i]);
    }

    return 0;
}
