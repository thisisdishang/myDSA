// Create a one-dimensional array with values 22,4,67,34,12,87,89,2656,9.
// Perform the following sorting operation on an array to sort the data in ascending order:-
//(a) Bubble sort
//(b) Insertion
//(c) Quick sort
//(d) Merge sort
#include <stdio.h>
int array[] = {22, 4, 67, 34, 12, 87, 89, 26, 56, 9};
int size = sizeof(array) / sizeof(array[0]);

void printArray(int array[]);

void swap(int *a, int *b)
{
    *a = (*a + *b) - (*b = *a);
}

void bubbleSort(int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < i; j++)
            if (array[i] < array[j])
                swap(&array[i], &array[j]);
}

void insertionSort(int size)
{
    int k, i;
    for (int j = 1; j < size; j++)
    {
        k = array[j];

        for (i = j - 1; k < array[i]; i--)
            array[i + 1] = array[i];

        array[i + 1] = k;
    }
    printArray(array);
}

int partition(int low, int high)
{
    int i = low - 1;
    int pivot = array[high];

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pivot = partition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }
}

void merge(int low, int mid, int high)
{
    int temp[size];
    int i = low;
    int j = mid + 1;
    int k = low;

    while ((i <= mid) && (j <= high))
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= high)
        temp[k++] = array[j++];

    for (int m = low; m < high; m++)
        array[m] = temp[m];
}

void mergeSort(int low, int high)
{
    int mid;
    if (low != high)
    {
        mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

void printArray(int array[])
{
    for (int i = 0; i < size; i++)
        printf("%3d ", array[i]);
    printf("\n");
}

int main()
{
    bubbleSort(size);

    insertionSort(size);

    quickSort(0, size - 1);

    mergeSort(0, 9);

    printArray(array);

    return 0;
}