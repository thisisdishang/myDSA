//Find the second largest element in the array and Reverse the array elements.
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(void)
{
    int larg,secondLarg,no,i;

    printf("\nEnter the number of elements in array: ");
    scanf("%d", &no);

    int arr[no];
    for (i = 0; i < no; i++)
        scanf("%d", &arr[i]);

    if (arr[0] > arr[1])
    {
        larg = arr[0];
        secondLarg = arr[1];
    }
    else
    {
        larg = arr[1];
        secondLarg = arr[0];
    }

    for (i = 2; i < no; i++)
    {
        if (arr[i] > larg)
        {
            secondLarg = larg;
            larg = arr[i];
        }
        else if (arr[i] > secondLarg)
            secondLarg = arr[i];
    }

    printf("\nSecond largest element is %d\n", secondLarg);

    int s = 0, e = no - 1;
    while (s < e)
        swap(&arr[s++], &arr[e--]);

    printf("\nReverse of array:-\n");
    for (int i = 0; i < no; i++)
        printf("%d ", arr[i]);
}