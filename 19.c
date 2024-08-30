// Power method
#include <stdio.h>
#include <math.h>

#define N 3 // Size of the matrix

void printVector(double vector[N]) {
    for (int i = 0; i < N; i++) {
        printf("%.4f\t", vector[i]);
    }
    printf("\n");
}

void multiplyMatrixVector(double A[N][N], double vector[N], double result[N]) {
    for (int i = 0; i < N; i++) {
        result[i] = 0;
        for (int j = 0; j < N; j++) {
            result[i] += A[i][j] * vector[j];
        }
    }
}

double calculateMagnitude(double vector[N]) {
    double magnitude = 0;
    for (int i = 0; i < N; i++) {
        magnitude += vector[i] * vector[i];
    }
    return sqrt(magnitude);
}

void normalizeVector(double vector[N]) {
    double magnitude = calculateMagnitude(vector);
    for (int i = 0; i < N; i++) {
        vector[i] /= magnitude;
    }
}

void powerMethod(double A[N][N], int maxIterations, double tolerance) {
    double eigenvalue = 0;
    double eigenvector[N] = {1, 1, 1}; // Initial guess for eigenvector
    double nextEigenvector[N];
    double lambda;

    int iteration = 0;
    double error = tolerance + 1; // Initialize error to ensure at least one iteration

    while (error > tolerance && iteration < maxIterations) {
        multiplyMatrixVector(A, eigenvector, nextEigenvector);

        // Calculate eigenvalue
        lambda = nextEigenvector[0] / eigenvector[0];
        eigenvalue = lambda;

        // Normalize eigenvector
        normalizeVector(nextEigenvector);

        // Calculate error
        error = 0;
        for (int i = 0; i < N; i++) {
            error += fabs(nextEigenvector[i] - eigenvector[i]);
        }

        // Update eigenvector
        for (int i = 0; i < N; i++) {
            eigenvector[i] = nextEigenvector[i];
        }

        iteration++;
    }

    if (error <= tolerance) {
        printf("Eigenvalue converged after %d iterations.\n", iteration);
        printf("Dominant eigenvalue: %.4f\n", eigenvalue);
        printf("Corresponding eigenvector:\n");
        printVector(eigenvector);
    } else {
        printf("Eigenvalue did not converge after %d iterations.\n", maxIterations);
    }
}

int main() {
    double A[N][N]; // Input matrix
    int maxIterations;
    double tolerance;

    // Input matrix
    printf("Enter coefficients of the matrix A (row-wise):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Input maximum number of iterations and tolerance
    printf("Enter maximum number of iterations: ");
    scanf("%d", &maxIterations);
    printf("Enter tolerance: ");
    scanf("%lf", &tolerance);

    // Perform power method
    powerMethod(A, maxIterations, tolerance);

    return 0;
}
