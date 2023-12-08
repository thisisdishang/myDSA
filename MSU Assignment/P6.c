//Implement Circular Queue using arrays that performs following operations:-
//(a) INSERT (b) DELETE (c) DISPLAY
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int cqueue[MAX];
int front, rear;

void insertData()
{
    int item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue is overflow");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    printf("\nInput an element for insert: ");
    scanf("%d", &item);
    cqueue[rear] = item;
}

void deleteData()
{
    if (front == -1)
    {
        printf("\nQueue is Underflow");
        return;
    }

    if (front == rear)
        front = rear = -1;
    else if (front == rear - 1)
        front = 0;
    else
        front++;
}

void displayCQ()
{
    int frontPos = front, rearPos = rear;
    if (front == -1)
    {
        printf("Queue is Underflow");
        return;
    }
    printf("\nQueue Elements:-\n");
    if (frontPos <= rearPos)
    {
        while (frontPos <= rearPos)
        {
            printf("%3d", cqueue[frontPos]);
            frontPos++;
        }
    }
    else
    {
        while (front <= MAX - 1)
        {
            printf("%3d", cqueue[frontPos]);
            frontPos++;
        }
        frontPos = 0;
        while (frontPos <= rearPos)
        {
            printf("%3d", cqueue[frontPos]);
            frontPos++;
        }
    }
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nCircular Queue Operation:-");
        printf("\n~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1.Insert\n2.Delete\n3.Display");

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
            displayCQ();
            break;
        default:
            printf("You choosed to exit..");
            exit(0);
        }
    }
    return 0;
}