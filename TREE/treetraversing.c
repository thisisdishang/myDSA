//Implement recursive and non-recursive tree traversing methods in-order, pre-order and post-order traversal.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform in-order traversal recursively
void inOrderRecursive(struct TreeNode* root) {
    if (root != NULL) {
        inOrderRecursive(root->left);
        printf("%d ", root->data);
        inOrderRecursive(root->right);
    }
}

// Function to perform pre-order traversal recursively
void preOrderRecursive(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }
}

// Function to perform post-order traversal recursively
void postOrderRecursive(struct TreeNode* root) {
    if (root != NULL) {
        postOrderRecursive(root->left);
        postOrderRecursive(root->right);
        printf("%d ", root->data);
    }
}

// Function to perform in-order traversal non-recursively using a stack
void inOrderNonRecursive(struct TreeNode* root) {
    struct TreeNode* stack[100];
    int top = -1;
    struct TreeNode* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to perform pre-order traversal non-recursively using a stack
void preOrderNonRecursive(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct TreeNode* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;

        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

// Function to perform post-order traversal non-recursively using two stacks
void postOrderNonRecursive(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* stack1[100];
    struct TreeNode* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        struct TreeNode* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;

        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Function to free memory allocated for the tree nodes
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Recursive In-order Traversal: ");
    inOrderRecursive(root);
    printf("\n");

    printf("Recursive Pre-order Traversal: ");
    preOrderRecursive(root);
    printf("\n");

    printf("Recursive Post-order Traversal: ");
    postOrderRecursive(root);
    printf("\n");

    printf("Non-Recursive In-order Traversal: ");
    inOrderNonRecursive(root);
    printf("\n");

    printf("Non-Recursive Pre-order Traversal: ");
    preOrderNonRecursive(root);
    printf("\n");

    printf("Non-Recursive Post-order Traversal: ");
    postOrderNonRecursive(root);
    printf("\n");

    // Free memory allocated for the tree nodes
    freeTree(root);

    return 0;
}