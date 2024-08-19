// Polynomial regression 
#include <stdio.h>

void polynomialRegression(double x[], double y[], int n, double *a0, double *a1, double *a2) {
    double sumx = 0, sumy = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0, sumxy = 0, sumx2y = 0;

    // Calculate sums
    for (int i = 0; i < n; i++) {
        double x2 = x[i] * x[i];
        sumx += x[i];
        sumy += y[i];
        sumx2 += x2;
        sumx3 += x2 * x[i];
        sumx4 += x2 * x2;
        sumxy += x[i] * y[i];
        sumx2y += x2 * y[i];
    }

    // Solve the system of equations
    double determinant = n * sumx2 * sumx4 + 2 * sumx * sumx2 * sumx3 - sumx * sumx * sumx4 - sumx2 * sumx2 * sumx2;
    *a0 = (sumy * sumx2 * sumx4 + sumx * sumx2y * sumx4 + sumx2 * sumxy * sumx3 - sumx2 * sumx2 * sumx2y - sumx * sumx * sumx4 - sumy * sumx2 * sumx3) / determinant;
    *a1 = (n * sumx2y * sumx4 + sumy * sumx3 * sumx2 + sumx * sumx2 * sumx2y - sumx2 * sumx2 * sumx2y - sumx * sumx * sumx2y - n * sumxy * sumx4) / determinant;
    *a2 = (n * sumxy * sumx2 - sumx * sumx3 - sumx * sumx * sumx2y + sumx2 * sumx2 * sumxy + sumy * sumx * sumx4 - n * sumx2 * sumx2y) / determinant;
}

int main() {
    int n;
    printf("Enter number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter values of x and f(x): ");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    double a0, a1, a2;
    polynomialRegression(x, y, n, &a0, &a1, &a2);

    printf("\nCoefficients of the polynomial regression (y = a0 + a1*x + a2*x^2):\n");
    printf("a0 = %.4lf\n", a0);
    printf("a1 = %.4lf\n", a1);
    printf("a2 = %.4lf\n", a2);

    return 0;
}
