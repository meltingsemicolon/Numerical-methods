// Newtons backward difference interpolation
#include <stdio.h>

double factorial(int n) {
    if (n <= 1) {
        return 1.0;
    } else {
        return n * factorial(n - 1);
    }
}

double newton_backward_difference(double x[], double y[], int n, double target) {
    double result = y[n - 1];
    double term = 1.0;
    double h = x[1] - x[0];

    double backward_diff[n][n];

    // Calculate backward differences
    for (int i = 0; i < n; i++) {
        backward_diff[i][0] = y[n - i - 1];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            backward_diff[i][j] = backward_diff[i + 1][j - 1] - backward_diff[i][j - 1];
        }
    }

    // Compute the interpolated value
    for (int i = 1; i < n; i++) {
        term *= (target - x[n - i]) / h;
        result += (term * backward_diff[0][i]) / factorial(i);
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n];
    double y[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the value of x and f(x) at position %d: ", i);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("Enter the target value for backward interpolation: ");
    double target;
    scanf("%lf", &target);

    // Interpolate
    double interpolated_value = newton_backward_difference(x, y, n, target);
    printf("Interpolated value at %lf: %lf\n", target, interpolated_value);

    return 0;
}
