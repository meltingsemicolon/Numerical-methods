// Jacobi iteration method
#include <stdio.h>
#include <math.h>

#define N 3 // Size of the system of equations

void printVector(double x[N]) {
    for (int i = 0; i < N; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }
}

void jacobiIteration(double A[N][N], double b[N], double x[N], int maxIterations, double tolerance) {
    double newX[N];
    int iteration = 0;
    double error = tolerance + 1; // Initialize error to ensure at least one iteration

    while (error > tolerance && iteration < maxIterations) {
        error = 0;
        for (int i = 0; i < N; i++) {
            newX[i] = b[i];
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    newX[i] -= A[i][j] * x[j];
                }
            }
            newX[i] /= A[i][i];
            error += fabs(newX[i] - x[i]);
        }
        for (int i = 0; i < N; i++) {
            x[i] = newX[i];
        }
        iteration++;
    }

    if (error <= tolerance) {
        printf("Solution converged after %d iterations.\n", iteration);
        printf("Solution:\n");
        printVector(x);
    } else {
        printf("Solution did not converge after %d iterations.\n", maxIterations);
    }
}

int main() {
    double A[N][N]; // Coefficients matrix
    double b[N];    // Right-hand side vector
    double x[N] = {0}; // Initial guess vector
    int maxIterations;
    double tolerance;

    // Input coefficients matrix
    printf("Enter coefficients of the matrix A (row-wise):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Input right-hand side vector
    printf("Enter coefficients of the vector b:\n");
    for (int i = 0; i < N; i++) {
        scanf("%lf", &b[i]);
    }

    // Input maximum number of iterations and tolerance
    printf("Enter maximum number of iterations: ");
    scanf("%d", &maxIterations);
    printf("Enter tolerance: ");
    scanf("%lf", &tolerance);

    // Perform Jacobi iteration
    jacobiIteration(A, b, x, maxIterations, tolerance);

    return 0;
}
