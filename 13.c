// Gaussian elemination method
#include <stdio.h>

#define N 3 // Size of the matrix

void printMatrix(double matrix[N][N+1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N+1; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussElimination(double matrix[N][N+1]) {
    // Forward Elimination
    for (int i = 0; i < N-1; i++) {
        for (int k = i+1; k < N; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < N+1; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Back Substitution
    double solution[N];
    for (int i = N-1; i >= 0; i--) {
        solution[i] = matrix[i][N];
        for (int j = i+1; j < N; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    // Print solution
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i+1, solution[i]);
    }
}

int main() {
    double matrix[N][N+1]; // Augmented matrix

    // Input augmented matrix
    printf("Enter augmented matrix coefficients (row-wise):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N+1; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Augmented Matrix:\n");
    printMatrix(matrix);
    printf("Performing gaussian method\n");

    // Perform Gaussian elimination
    gaussElimination(matrix);

    return 0;
}
