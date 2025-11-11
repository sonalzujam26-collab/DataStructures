#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Structure for tree node
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* newNode(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node into BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function for inorder traversal (for display)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to find height (longest path from root)
int height(struct node* root) {
    if (root == NULL)
        return 0;
    else {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

// Function to find minimum value in BST
int findMin(struct node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    struct node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current->data;
}

// Function to swap left and right pointers at every node (mirror tree)
void mirror(struct node* root) {
    struct node* temp;
    if (root == NULL)
        return;

    mirror(root->left);
    mirror(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Function to search a value in BST
int search(struct node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Main function
void main() {
    struct node* root = NULL;
    int choice, value, n, i, key;

    clrscr();

    printf("Enter number of nodes to insert initially: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    do {
        printf("\n\n------ MENU ------\n");
        printf("1. Insert new node\n");
        printf("2. Find number of nodes in longest path (Height)\n");
        printf("3. Find minimum value in tree\n");
        printf("4. Mirror the tree (swap left-right)\n");
        printf("5. Search a value\n");
        printf("6. Display inorder traversal\n");
        printf("7. Exit\n");
        printf("------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Node inserted!\n");
            break;

        case 2:
            printf("Longest path (height) = %d\n", height(root));
            break;

        case 3:
            printf("Minimum value in tree = %d\n", findMin(root));
            break;

        case 4:
            mirror(root);
            printf("Tree mirrored (left and right swapped)!\n");
            break;

        case 5:
            printf("Enter value to search: ");
            scanf("%d", &key);
            if (search(root, key))
                printf("Value found in the tree!\n");
            else
                printf("Value not found!\n");
            break;

        case 6:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 7);

    getch();
}
