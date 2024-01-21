//Implement a program for stack that performs following operations using arrays:-
//(a) PUSH (b) POP (c) PEEP (d) CHANGE (e) DISPLAY
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int arr[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

void push(int data)
{
    if (isFull())
    {
        printf("\nStack is overflow...");
        return;
    }
    else
        arr[++top] = data;
}

int pop()
{
    if (isEmpty())
    {
        printf("\nStack is underflow..");
        return -1;
    }
    printf("%d is pop out",arr[top]);
    return arr[top--];
}

void display()
{
    if (isEmpty())
    {
        printf("\nStack is underflow..");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%3d\n", arr[i]);
}

void peep()
{
    if (isEmpty())
    {
        printf("Your Stack is underflow..");
        return;
    }
    printf("top most element is %d", arr[top]);
}

int main()
{
    int choice, updateData;
    while (1)
    {
        printf("\nSTACK Operation:-");
        printf("\n~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Push the element");
        printf("\n2. Pop the top element");
        printf("\n3. Display the stack");
        printf("\n4. Display the top element");
        printf("\n5. Update the top element");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element: ");
            scanf("%d", &updateData);
            push(updateData);
            break;

        case 2:
            pop();
            break;


        case 3:
            display();
            break;

        case 4:
            peep();
            break;

        case 5:
            printf("Enter the value to change: ");
            scanf("%d", &updateData);
            pop();
            push(updateData);
            break;

        case 6:
            printf("You choosed to exit..");
            exit(1);

        default:
            printf("\nInvalid choice...try again...");
        }
    }
    return 0;
}