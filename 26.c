// Maxima and minima of tavulated functions
#include <stdio.h>

// Function to calculate the derivative at a given point using forward difference method
double derivative(double x[], double y[], int n, int i) {
    double h = x[1] - x[0];
    if (i == 0) {
        return (y[i+1] - y[i]) / h;
    } else if (i == n - 1) {
        return (y[n-1] - y[n-2]) / h;
    } else {
        return (y[i+1] - y[i-1]) / (2 * h);
    }
}

int main() {
    int n=0;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the values of x and f(x) for each data point:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Find critical points
    printf("Critical points (x, f'(x)):\n");
    for (int i = 1; i < n - 1; i++) {
        double d = derivative(x, y, n, i);
        printf("(%lf, %lf)\n", x[i], d);
    }

    // Find maxima and minima using the first derivative test
    printf("Maxima and minima:\n");
    for (int i = 1; i < n - 1; i++) {
        double d1 = derivative(x, y, n, i - 1);
        double d2 = derivative(x, y, n, i);
        double d3 = derivative(x, y, n, i + 1);
        
        if (d1 * d2 < 0 && d2 * d3 < 0) {
            printf("Maximum at (%lf, %lf)\n", x[i], y[i]);
        } else if (d1 * d2 > 0 && d2 * d3 > 0) {
            printf("Minimum at (%lf, %lf)\n", x[i], y[i]);
        }
    }

    return 0;
}
