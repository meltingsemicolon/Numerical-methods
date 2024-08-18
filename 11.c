// Non-linear regression with exopnential model
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float sumx = 0, sumlogy = 0, sumxlogy = 0, sumxsq = 0;
    float a, b;

    // Input
    printf("Enter number of data points: ");
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
        sumlogy += log(y[i]);  // Take natural logarithm of y for exponential model
        sumxlogy += x[i] * log(y[i]);  // Multiply x by the natural logarithm of y
        sumxsq += x[i] * x[i];
    }

    // Calculate coefficients
    b = (n * sumxlogy - sumx * sumlogy) / (n * sumxsq - sumx * sumx);
    a = exp((sumlogy - b * sumx) / n);  // Calculate 'a' by taking exponential of the mean of log(y)

    // Output results
    printf("\nParameter 'a': %.2f\n", a);
    printf("Parameter 'b': %.2f\n", b);
    printf("Equation of the Exponential Model: y = %.2fe^(%.2fx)\n", a, b);

    return 0;
}
