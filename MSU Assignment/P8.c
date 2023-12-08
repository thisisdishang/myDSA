// Write a program to implement following operations on the doubly linked list:-
//(a) Insert a node at the front of the linked list.
//(b) Insert a node at the end of the linked list.
//(c) Delete the last node of the linked list.
//(d) Delete a node before specified position.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

struct Node *GetNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertHead(int x)
{
    struct Node *newNode = GetNewNode(x); // return the address of the newly created node
    if (head == NULL)                     // If list is empty  OR  you're going to insert first node
    {
        head = newNode;
        return;
    }
    head->prev = newNode; // set the previous field of existing head node as the address of the newNode
    newNode->next = head; // set the next field of the new node to the head
    head = newNode;
}

void InsertTail(int x) // You can only insert element if list has at least one element
{
    struct Node *q;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
    else
    {
        q = head;
        while (q->next != NULL)
            q = q->next;

        q->next = temp;
        temp->prev = q;
    }
}

void print()
{
    struct Node *temp = head;
    printf("\nList is : ");
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void del(int n)
{
    struct Node *q, *temp;
    if (head->data == n)
    {
        temp = head;
        head = head->next; // first element deleted
        head->prev = NULL;
        free(temp);
        return;
    }
    q = head;
    while (q->next->next != NULL)
    {
        if (q->next->data == n) // Element deleted in between
        {
            temp = q->next;
            q->next = temp->next;
            temp->next->prev = q;
            free(temp);
            return;
        }
        q = q->next;
    }
    if (q->next->data == n) // last element Deleted
    {
        temp = q->next;
        free(temp);
        q->next = NULL;
        return;
    }
    printf("\nElement %d is not found in list\n", n);
}

int main()
{
    head = NULL;
    int choice = 0, n, m, pos;

    while (1)
    {
        printf("\nDoubly linked list Operation:-");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n 1. Add at beginning");
        printf("\n 2. Add at last position");
        printf("\n 3. Delete element");
        printf("\n 4. Display");
        printf("\n 5. Exit");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element: ");
            scanf("%d", &m);
            InsertHead(m);
            break;

        case 2:
            printf("\nEnter the element: ");
            scanf("%d", &m);
            InsertTail(m);
            break;

        case 3:
            if (head == NULL)
            {
                printf("\nList is empty  ");
                continue;
            }
            print();
            printf("\nEnter the element you want to delete ");
            scanf("%d", &m);
            del(m);
            break;

        case 4:
            print();
            break;

        case 5:
            exit(0);

        default: printf("\nInvalid choice...");
        }
    }
}