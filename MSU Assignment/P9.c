//C program to create a Binary search tree.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *GetNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// void Insert(struct Node *root, int data)
struct Node *Insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);

    return root;
}

struct Node *Delete(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    else if (data < root->data)
        root->left = Delete(root->left, data);

    else if (data > root->data)
        root->right = Delete(root->right, data);

    else
    {
        // Case 1: No Child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }

        // Case 2: One Child
        else if (root->left == NULL)
        {
            struct Node *temp = root; // store the address of the current node to the temp-node you want to delete
            root = root->right;       // move the root to the right
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root; // store the address of the current node to the temp-node you want to delete
            root = root->left;        // move the root to the left
            free(temp);
        }

        // Case 3: Two Children
        else
        {
            struct Node *temp = RecMin(root->right);
            root->data = temp->data;                       // set the data to the current node
            root->right = Delete(root->right, temp->data); // delete the min. value from the right-tree
        }
    }
    return root;
}

void PreOrder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%2d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct Node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%2d ", root->data);
    InOrder(root->right);
}

void PostOrder(struct Node *root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%2d ", root->data);
}

int RecMin(struct Node *root)
{
    if (root==NULL){
        printf("list is empty");
        return -1;
    }
    else
    {
        if (root->left==NULL)
        {
            return root->data;
        }        
    }
    RecMin(root->left);
}

int main(void)
{
    struct Node *root = NULL; // a pointer for the root, not root itself.
    int choice, n, ele;

    while (1)
    {
        printf("\n1.  Insert a NewNode");
        printf("\n2.  Enter Multiple Nodes at a time");
        printf("\n3.  Delete a Node");
        printf("\n4.  Display Tree in PreOrder   (root, left,  right)");
        printf("\n5.  Display Tree in InOrder    (left, root,  right)");
        printf("\n6.  Display Tree in PostOrder  (left, right, root)");
        printf("\n7.  Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {

        case 1:
            printf("Enter the element: ");
            scanf("%d", &n);
            root = Insert(root, n);
            break;

        case 2:
            printf("Enter the number of elements: ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++)
            {
                printf("\nEnter Node Value: ");
                scanf("%d", &ele);
                root = Insert(root, ele);
            }
            break;

        case 3:
            printf("Enter the element to delete: ");
            scanf("%d", &ele);
            root = Delete(root, ele);
            break;

        case 4:
            printf("Your tree in PreOrder:\n");
            PreOrder(root);
            break;

        case 5:
            printf("Your tree in InOrder:\n");
            InOrder(root);
            break;

        case 6:
            printf("Your tree in PostOrder:\n");
            PostOrder(root);
            break;

        default:
            exit(0);
        }
    }
}