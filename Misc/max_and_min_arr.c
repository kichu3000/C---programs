#include <stdio.h>
#include "timer.h"
int findMax(int arr[], int n);
int findMin(int arr[], int n);

int main()
{
    clock_t start = startTimer();
    int arr[] = {12, 45, 3, 22, 78, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = findMax(arr, n);
    int min = findMin(arr, n);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    endTimer(start, "Execution time:");
    return 0;
}

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int findMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
