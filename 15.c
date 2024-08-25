// DO-little algorithm of LU decomposition
#include <stdio.h>

#define N 3 // Size of the matrix

void printMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void doolittleLU(double matrix[N][N]) {
    double L[N][N] = {0}; // Lower triangular matrix
    double U[N][N]; // Upper triangular matrix

    // Perform LU decomposition
    for (int i = 0; i < N; i++) {
        // Upper triangular matrix
        for (int k = i; k < N; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = matrix[i][k] - sum;
        }

        // Lower triangular matrix
        L[i][i] = 1; // Diagonal elements of L are 1
        for (int k = i+1; k < N; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[k][j] * U[j][i]);
            }
            L[k][i] = (matrix[k][i] - sum) / U[i][i];
        }
    }

    // Print L and U matrices
    printf("Lower Triangular Matrix (L):\n");
    printMatrix(L);
    printf("\nUpper Triangular Matrix (U):\n");
    printMatrix(U);
}

int main() {
    double matrix[N][N]; // Input matrix

    // Input matrix
    printf("Enter matrix coefficients (row-wise):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Input Matrix:\n");
    printMatrix(matrix);

    // Perform Doolittle LU decomposition
    doolittleLU(matrix);

    return 0;
}
