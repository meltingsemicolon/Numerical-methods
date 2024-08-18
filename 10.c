// Linera regression
#include <stdio.h>

int main()
{
    int n;
    float sumx = 0, sumy = 0, sumxy = 0, sumxsq = 0;
    float a, b;

    // Input
    printf("Enter number of observations: ");
    scanf("%d", &n);

    float x[n], y[n];
    printf("Enter values of x and f(x): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }

    // Calculate sums
    for (int i = 0; i < n; i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumxsq += x[i] * x[i];
    }

    // Calculate coefficients
    b = (n * sumxy - sumx * sumy) / (n * sumxsq - sumx * sumx);
    a = (sumy - b * sumx) / n;

    // Output results
    printf("\nIntercept (a): %.2f\n", a);
    printf("Slope (b): %.2f\n", b);
    printf("Equation of the Line: y = %.2fx + %.2f\n", b, a);

    return 0;
}
