// Cholesky's algorithnm of LU decompostiton
#include <stdio.h>
#include <math.h>

#define N 3 // Size of the matrix

void printMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void choleskyDecomposition(double matrix[N][N]) {
    double L[N][N] = {0}; // Lower triangular matrix

    // Perform Cholesky decomposition
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            if (j == i) {
                for (int k = 0; k < j; k++) {
                    sum += L[j][k] * L[j][k];
                }
                L[j][j] = sqrt(matrix[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++) {
                    sum += (L[i][k] * L[j][k]);
                }
                L[i][j] = (matrix[i][j] - sum) / L[j][j];
            }
        }
    }

    // Print L matrix
    printf("Lower Triangular Matrix (L):\n");
    printMatrix(L);
}

int main() {
    double matrix[N][N]; // Input matrix

    // Input matrix
    printf("Enter symmetric positive definite matrix coefficients (row-wise):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Input Matrix:\n");
    printMatrix(matrix);

    // Perform Cholesky decomposition
    choleskyDecomposition(matrix);

    return 0;
}
