// langrange's method
#include <stdio.h>

double lagrange_interpolation(double x[], double y[], int n, double xi) {
    double result = 0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the value of x and fx at i=%d\n",i);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double xi;
    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &xi);

    double interpolated_value = lagrange_interpolation(x, y, n, xi);
    printf("Interpolated value at x = %.2lf: %.4lf\n", xi, interpolated_value);

    return 0;
}
