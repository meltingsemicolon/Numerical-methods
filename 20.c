// Two-point difference formula
#include <stdio.h>
#include <math.h>

double centralDifference(double x[], double y[], int n, double target) {
    double h = x[1] - x[0];
    double derivative;

    // Find the index i such that x[i] is closest to the target
    int i = 0;
    while (i < n && target > x[i]) {
        i++;
    }

    // Use central difference formula to approximate the derivative
    if (i == 0) {
        derivative = (y[i+1] - y[i]) / h;
    } else if (i == n) {
        derivative = (y[i] - y[i-1]) / h;
    } else {
        derivative = (y[i+1] - y[i-1]) / (2 * h);
    }

    return derivative;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the values of x and f(x) for each data point:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double target;
    printf("Enter the target value for which you want to approximate the derivative: ");
    scanf("%lf", &target);

    // Approximate derivative using central difference formula
    double derivative = centralDifference(x, y, n, target);
    printf("Approximated derivative at %lf: %lf\n", target, derivative);

    return 0;
}
