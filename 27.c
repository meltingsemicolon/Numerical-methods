// Trapezoidal rule
#include <stdio.h>

// Function to integrate
double func(double x) {
    return x*x -12*x; // Change this to the function you want to integrate
}

// Trapezoidal rule implementation
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (func(a) + func(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += func(x);
    }

    return h * sum;
}

int main() {
    double a, b; // Limits of integration
    int n;       // Number of intervals

    // Input
     printf("Enter lower and upper limit  of integration: ");
    scanf("%lf%lf", &a,&b);
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    // Calculating the integral using trapezoidal rule
    double integral = trapezoidal(a, b, n);

    // Output
    printf("Approximate integral using trapezoidal rule: %lf\n", integral);

    return 0;
}
