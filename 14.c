// Gauss jordan method
#include <stdio.h>
#define N 3 // Size of the matrix
void printMatrix(double matrix[N][N + 1])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussJordan(double matrix[N][N + 1])
{
    // Forward Elimination
    for (int i = 0; i < N; i++)
    {
        // Pivot for column
        double pivot = matrix[i][i];

        // Make the diagonal element 1
        for (int j = i; j < N + 1; j++)
        {
            matrix[i][j] /= pivot;
        }

        // Make the other elements in the column 0
        for (int k = 0; k < N; k++)
        {
            if (k != i)
            {
                double factor = matrix[k][i];
                for (int j = i; j < N + 1; j++)
                {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }

    // Print solution
    printf("Solution:\n");
    for (int i = 0; i < N; i++)
    {
        printf("x%d = %.2f\n", i + 1, matrix[i][N]);
    }
}

int main()
{
    double matrix[N][N + 1]; // Augmented matrix

    // Input augmented matrix
    printf("Enter augmented matrix coefficients (row-wise):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Augmented Matrix:\n");
    printMatrix(matrix);

    // Perform Gauss-Jordan elimination
    gaussJordan(matrix);

    return 0;
}
