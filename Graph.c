#include <stdio.h>

#define MAX 30

struct Edge {
    int u, v, w;
};

int parent[MAX];
struct Edge edges[MAX];
int n, e;

// Function to find parent of a node
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union
void union_func(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Function to sort edges by cost (Bubble Sort)
void sortEdges() {
    int i, j;
    struct Edge temp;
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Function to find Minimum Spanning Tree
void kruskal() {
    int i, j;
    int total_cost = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    sortEdges();

    printf("\nEdges in the Minimum Cost Connection:\n");
    for (i = 0, j = 0; j < n - 1 && i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            union_func(u, v);
            printf("(%d, %d)  cost = %d\n", u, v, w);
            total_cost += w;
            j++;
        }
    }

    printf("\nMinimum Total Cost = %d\n", total_cost);
}

// Function to input data
void inputData() {
    int i;
    printf("Enter number of offices: ");
    scanf("%d", &n);

    printf("Enter number of possible connections: ");
    scanf("%d", &e);

    printf("\nEnter the connections as (office1 office2 cost):\n");
    for (i = 0; i < e; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Enter office data\n");
        printf("2. Find Minimum Cost Connection (Kruskal’s Algorithm)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputData();
                break;

            case 2:
                kruskal();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
