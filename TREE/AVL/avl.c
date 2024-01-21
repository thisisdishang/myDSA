//Implement AVL tree.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
    int ht;
} node;

int Height(node *t)
{
    int lh, rh;
    if (t == NULL)
        return 0;
    if (t->left == NULL)
        lh = 0;
    else
        lh = 1 + t->left->ht;

    if (t->right == NULL)
        rh = 0;
    else
        rh = 1 + t->right->ht;
    return (lh > rh ? lh : rh);
}

int baseFactor(node *t)
{
    int lh, rh;

    if (t == NULL)
        return 0;
    if (t->left == NULL)
        lh = 0;
    else
        lh = 1 + t->left->ht;

    if (t->right == NULL)
        rh = 0;
    else
        rh = 1 + t->right->ht;
    return (lh - rh);
}

node *RotateLeft(node *t)
{
    node *y = t->right;
    t->right = y->left;
    y->left = t;
    t->ht = Height(t);
    y->ht = Height(y);

    return y;
}

node *RotateRight(node *t)
{
    node *y = t->left;
    t->left = y->right;
    y->right = t;
    t->ht = Height(t);
    y->ht = Height(y);
}

node *RR(node *t)
{
    t = RotateLeft(t);
    return t;
}

node *LL(node *t)
{
    t = RotateRight(t);
    return t;
}

node *LR(node *t)
{
    t->left = RotateLeft(t->left);
    t = RotateRight(t);
    return t;
}

node *RL(node *t)
{
    t->right = RotateRight(t->right);
    t = RotateLeft(t);
    return t;
}
node *Insert(node *t, int x)
{
    if (t == NULL) // insertion of first element
    {
        t = (node *)malloc(sizeof(node));
        t->data = x;
        t->left = NULL;
        t->right = NULL;
    }
    else if (x > t->data)
    {
        t->right = Insert(t->right, x);
        if (baseFactor(t) == -2)
            if (x > t->right->data)
                t = RR(t);
            else
                t = RL(t);
    }
    else if (x < t->data)
    {
        t->left = Insert(t->left, x);
        if (baseFactor(t) == 2)
            if (x < t->left->data)
                t = LL(t);
            else
                t = LR(t);
    }

    t->ht = Height(t);

    return t;
}

node *Delete(node *t, int x)
{
    node *p;

    if (t == NULL)
        return NULL;
    else if (x > t->data)
    {
        t->right = Delete(t->right, x);

        if (baseFactor(t) == 2)
            if (baseFactor(t->left) >= 0)
                t = LL(t);
            else
                t = LR(t);
    }
    else if (x < t->data)
    {
        t->left = Delete(t->left, x);

        if (baseFactor(t) == -2)
            if (baseFactor(t->right) <= 0)
                t = RR(t);
            else
                t = RL(t);
    }
    else
    {
        if (t->right != NULL)
        // data to be delete is not found
        {
            p = t->right;

            while (p->left != NULL)
                p = p->left;

            t->data = p->data;
            t->right = Delete(t->right, p->data);
            if (baseFactor(t) == 2) // Rebalancing during windup
                if (baseFactor(t->left) >= 0)
                    t = LL(t);
                else
                    t = LR(t);
        }
        else
            return t->left;
    }
    t->ht = Height(t);
    return t;
}

void PreOrder(node *t)
{
    if (t != NULL)
    {
        printf(" %d (baseFactor = %d) ", t->data, baseFactor(t));
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void InOrder(node *t)
{
    if (t != NULL)
    {
        InOrder(t->left);
        printf(" %d (baseFactor = %d) ", t->data, baseFactor(t));
        InOrder(t->right);
    }
}

int main(void)
{
    node *root = NULL;
    int choice, x;

    while (1)
    {
        printf("\n1. Create a new");
        printf("\n2. Insert");
        printf("\n3. Delete");
        printf("\n4. Display PreOrder");
        printf("\n5. Display InOrder");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("\nEnter the number of elements: ");
            scanf("%d", &x);

            root = NULL;

            printf("\nEnter Tree data\n");
            for (int i = 0; i < x; i++)
            {
                scanf("%d", &x);
                root = Insert(root, x);
            }

            break;

        case 2:
            printf("\nEnter a data to insert: ");
            scanf("%d", &x);

            root = Insert(root, x);

            break;

        case 3:
            printf("\nEnter a data to delete: ");
            scanf("%d", &x);

            root = Delete(root, x);

            break;

        case 4:
            printf("\nPreOrder: ");
            PreOrder(root);

            break;

        case 5:
            printf("\nInOrder: ");
            InOrder(root);

            break;

        default:
            exit(0);
        }
    }
}