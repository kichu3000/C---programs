#include <stdio.h>
void swap(int *, int *);
int partition(int[], int, int);

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = low;
    int big = low + 1;
    int small = high;

    while (big < small)
    {
        while (arr[big] < arr[pivot])
        {
            big++;
        }
        while (arr[small] > arr[pivot])
        {
            small--;
        }
        if (big < small)
        {
            swap(&arr[big], &arr[small]);
        }
    }
    swap(&arr[pivot], &arr[small]);

    return small;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n = 10;
    int arr[] = {5, 2, 8, 4, 9, 1, 6, 3, 9, 6};
    quickSort(arr, 0, n - 1);

    printf("Sorted array is ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}