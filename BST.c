#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

// Create new node
struct node* newNode(int val) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Insert node in BST
struct node* insert(struct node *root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// Display (Inorder)
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Find height (longest path)
int height(struct node *root) {
    if (root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

// Find minimum value
void findMin(struct node *root) {
    if (root == NULL) {
        printf("\nTree is empty.\n");
        return;
    }
    while (root->left != NULL)
        root = root->left;
    printf("\nMinimum value: %d\n", root->data);
}

// Mirror tree
void mirror(struct node *root) {
    if (root == NULL) return;
    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

// Search value
void search(struct node *root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            printf("\nValue found!\n");
            return;
        }
        root = (key < root->data) ? root->left : root->right;
    }
    printf("\nValue not found!\n");
}

// Main function
int main() {
    int ch, val;
    do {
        printf("\n\n--- BINARY SEARCH TREE ---");
        printf("\n1. Insert");
        printf("\n2. Display (Inorder)");
        printf("\n3. Find Longest Path");
        printf("\n4. Find Minimum Value");
        printf("\n5. Mirror Tree");
        printf("\n6. Search Value");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Inserted!\n");
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nLongest path length: %d\n", height(root));
                break;
            case 4:
                findMin(root);
                break;
            case 5:
                mirror(root);
                printf("\nTree mirrored!\n");
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(root, val);
                break;
            case 7:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (ch != 7);

    return 0;
}
