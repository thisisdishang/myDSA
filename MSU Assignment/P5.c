//Implement Queue using arrays that performs following operations:-
//(a) INSERT (b) DELETE (c) DISPLAY
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int qArray[MAX];
int front = -1;
int rear = -1;

void insertData()
{
    int element;
    if (rear == MAX - 1)
    {
        printf("\nQueue is overflow\n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        printf("\nInput the element for add in queue: ");
        scanf("%d", &element);
        qArray[++rear] = element;
    }
} // end of insert

void deleteData()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is underflow");
        return;
    }
    else
        printf("\nElement deleted from queue is: %d\n", qArray[front++]);
}

void displayQ()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        printf("\nQueue is: \n");
        for (int i = front; i <= rear; i++)
            printf("%2d ", qArray[i]);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\nQueue Operation:-");
        printf("\n~~~~~~~~~~~~~~~~~~~~~");
        printf("\n 1. Insert");
        printf("\n 2. Delete");
        printf("\n 3. Display");
        printf("\n 4. Quit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertData();
            break;
        case 2:
            deleteData();
            break;
        case 3:
            displayQ();
            break;
        default:
            exit(1);
        }
    }
}