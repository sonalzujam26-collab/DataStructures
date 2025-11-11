#include <stdio.h>

void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    float percent[100];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter percentage of %d students:\n", n);
    for(i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &percent[i]);
    }

    bubbleSort(percent, n);

    printf("\nPercentages in Ascending Order:\n");
    for(i = 0; i < n; i++) {
        printf("%.2f\t", percent[i]);
    }

    printf("\n\nTop 5 Scores:\n");
    // Display from the end (highest values)
    for(i = n - 1; i >= n - 5 && i >= 0; i--) {
        printf("%.2f\t", percent[i]);
    }

    return 0;
}
