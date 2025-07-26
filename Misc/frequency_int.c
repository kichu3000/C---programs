#include <stdio.h>
void count_frequency(int arr[], int n)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }
        visited[i] = 1;
        printf("%d -> %d times\n", arr[i], count);
    }
}

int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    count_frequency(arr, n);

    return 0;
}
