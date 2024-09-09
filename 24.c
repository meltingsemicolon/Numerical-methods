// Newton's backward diffence formula for equal interval
#include <stdio.h>
#include <math.h>

double newtonsBackwardDifference(double x[], double y[], int n, double target) {
    double h = x[1] - x[0];
    double derivative = 0;

    // Find the index i such that x[i] is closest to the target
    int i = 0;
    while (i < n && target > x[i]) {
        i++;
    }
    
    // Ensure that at least two points are available before the target
    if (i > 0) {
        // Use Newton's backward difference formula to approximate the derivative
        derivative = (y[i] - y[i-1]) / h;
    } else {
        printf("Insufficient data points before the target.\n");
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

    // Approximate derivative using Newton's backward difference formula
    double derivative = newtonsBackwardDifference(x, y, n, target);
    printf("Approximated derivative at %lf: %lf\n", target, derivative);

    return 0;
}
