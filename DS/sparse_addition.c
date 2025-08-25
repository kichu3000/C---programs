#include <stdio.h>
#define MAX 100

// Define structure for Sparse Matrix elements
typedef struct
{
    int row;
    int col;
    int value;
} Element;

int main()
{
    Element A[MAX], B[MAX], C[MAX];
    int i, j, k;

    int m, n, tA, tB; // rows, columns, non-zero elements in A and B

    // Input Sparse Matrix A
    printf("Enter rows, columns and number of non-zero elements of Matrix A: ");
    scanf("%d %d %d", &A[0].row, &A[0].col, &A[0].value);
    tA = A[0].value;

    printf("Enter elements (row column value) for Matrix A:\n");
    for (i = 1; i <= tA; i++)
    {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value);
    }

    // Input Sparse Matrix B
    printf("Enter rows, columns and number of non-zero elements of Matrix B: ");
    scanf("%d %d %d", &B[0].row, &B[0].col, &B[0].value);
    tB = B[0].value;

    printf("Enter elements (row column value) for Matrix B:\n");
    for (i = 1; i <= tB; i++)
    {
        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);
    }

    // Check if addition is possible
    if (A[0].row != B[0].row || A[0].col != B[0].col)
    {
        printf("Addition not possible. Matrix dimensions do not match.\n");
        return 0;
    }

    // Initialize pointers
    i = j = k = 1;
    C[0].row = A[0].row;
    C[0].col = A[0].col;

    // Merge and Add
    while (i <= tA && j <= tB)
    {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
        {
            C[k++] = A[i++];
        }
        else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col))
        {
            C[k++] = B[j++];
        }
        else
        { // Same position
            int sum = A[i].value + B[j].value;
            if (sum != 0)
            {
                C[k].row = A[i].row;
                C[k].col = A[i].col;
                C[k].value = sum;
                k++;
            }
            i++;
            j++;
        }
    }

    // Copy remaining elements of A
    while (i <= tA)
    {
        C[k++] = A[i++];
    }

    // Copy remaining elements of B
    while (j <= tB)
    {
        C[k++] = B[j++];
    }

    C[0].value = k - 1; // Update number of non-zero elements

    // Display Result
    printf("\nResultant Sparse Matrix (row column value):\n");
    for (i = 0; i < k; i++)
    {
        printf("%d %d %d\n", C[i].row, C[i].col, C[i].value);
    }

    return 0;
}
