#include <stdio.h>
void count_frequency(char arr[], int n)
{
    int freq[256] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int printed[256] = {0};
    for (int i = 0; i < n; i++)
    {
        if (!printed[(unsigned char)arr[i]])
        {
            printf("%c -> %d times\n", arr[i], freq[arr[i]]);
            printed[arr[i]] = 1;
        }
    }
}

int main()
{
    char arr[] = "apple";
    int n = sizeof(arr) - 1;
    count_frequency(arr, n);
    return 0;
}