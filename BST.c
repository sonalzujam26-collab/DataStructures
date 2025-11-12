#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

// Function to create a new node
struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node
struct node* insert(struct node *root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void insertNode() {
    int value;
    printf("\nEnter value to insert: ");
    scanf("%d", &value);
    root = insert(root, value);
    printf("Node inserted.\n");
}

// Function to find height (longest path)
int height(struct node *root) {
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    if (left > right)
        return left + 1;
    else
        return right + 1;
}

void findLongestPath() {
    printf("\nNumber of nodes in longest path: %d\n", height(root));
}

// Function to find minimum value
void findMinValue() {
    struct node *temp = root;
    if (temp == NULL) {
        printf("\nTree is empty.\n");
        return;
    }
    while (temp->left != NULL)
        temp = temp->left;
    printf("\nMinimum value in tree: %d\n", temp->data);
}

// Function to mirror the tree
void mirror(struct node *root) {
    struct node *temp;
    if (root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void mirrorTree() {
    mirror(root);
    printf("\nTree mirrored successfully.\n");
}

// Function to search a value
void searchValue() {
    int key;
    struct node *temp = root;
    printf("\nEnter value to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (key == temp->data) {
            printf("Value found in tree.\n");
            return;
        } else if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Value not found in tree.\n");
}

// Inorder display
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void displayTree() {
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\n");
}

// Menu function
void menu() {
    printf("\n--- BINARY SEARCH TREE OPERATIONS ---");
    printf("\n1. Insert Node");
    printf("\n2. Find Longest Path");
    printf("\n3. Find Minimum Value");
    printf("\n4. Mirror the Tree");
    printf("\n5. Search a Value");
    printf("\n6. Display Tree (Inorder)");
    printf("\n7. Exit");
    printf("\nEnter your choice: ");
}

// Main function
int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertNode(); break;
            case 2: findLongestPath(); break;
            case 3: findMinValue(); break;
            case 4: mirrorTree(); break;
            case 5: searchValue(); break;
            case 6: displayTree(); break;
            case 7: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
