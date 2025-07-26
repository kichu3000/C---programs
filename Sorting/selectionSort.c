#include <stdio.h>
void swap(int *, int *);
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);
    }

    printf("Sorted array is ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[50] = {
        23, 5, 12, 78, 45, 32, 5, 9, 90, 17,
        4, 88, 61, 1, 29, 72, 0, 3, 49, 33,
        99, 11, 26, 17, 53, 36, 70, 91, 100, 2,
        13, 42, 66, 8, 21, 37, 94, 18, 55, 14,
        19, 73, 46, 81, 10, 67, 31, 20, 39, 6};

    selectionSort(arr, 50);
}
