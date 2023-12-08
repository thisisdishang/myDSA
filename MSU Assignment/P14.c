//C program to implement Binary Search.
#include <stdio.h>
int binarySearch(int a[], int element, int left, int right)
{
    int mid, c = 0;
    if (left <= right)
    {
        mid = (left + right) / 2;
        if (element == a[mid])
            c = 1;
        else if (element < a[mid])
            return binarySearch(a, element, left, mid - 1);
        else
            return binarySearch(a, element, mid + 1, right);
    }
    else
        return c;
}

int main(void)
{
    int i, n, element, c, left = 0;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int arr[n], right = n - 1;

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nEnter the number to search : ");
    scanf("%d", &element);

    c = binarySearch(arr, element, left, right);

    (c == 0) ? printf("\n%d not found", element) : printf("\n%d is found", element);
}