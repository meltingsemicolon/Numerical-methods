// Netwon's dividend difference interpolation
#include <stdio.h>

double divided_difference(double x[], double y[], int i, int j)
{
    if (j == 0)
    {
        return y[i];
    }
    else
    {
        return (divided_difference(x, y, i + 1, j - 1) - divided_difference(x, y, i, j - 1)) / (x[i + j] - x[i]);
    }
}

double newton_interpolation(double x[], double y[], int n, double target)
{
    double result = 0.0;
    double term = 1.0;

    for (int j = 0; j < n; j++)
    {
        result += term * divided_difference(x, y, 0, j);
        term *= (target - x[j]);
    }

    return result;
}

int main()
{

    int n;
    printf("Enter the no of data points: ");
    scanf("%d", &n);
    double x[n];
    double y[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of x and fx at %d place\n", i);
        scanf("%lf%lf",&x[i],&y[i]);
    }
printf("Enter the target value for interpolation: ");
    double target;
    scanf("%lf",&target);

    // Interpolate
    double interpolated_value = newton_interpolation(x, y, n, target);
    printf("Interpolated value at %.2lf is: %.4lf\n", target, interpolated_value);

    return 0;
}
