// newtons forward differnce interpolation
#include <stdio.h>

double factorial(int n)
{
    if (n <= 1)
    {
        return 1.0;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

double newton_forward_difference(double x[], double y[], int n, double target)
{
    double result = y[0];
    double term = 1.0;
    double h = x[1] - x[0];

    double forward_diff[n][n];

    // Calculate forward differences
    for (int i = 0; i < n; i++)
    {
        forward_diff[i][0] = y[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            forward_diff[i][j] = forward_diff[i + 1][j - 1] - forward_diff[i][j - 1];
        }
    }

    // Compute the interpolated value
    for (int i = 1; i < n; i++)
    {
        term *= (target - x[i - 1]) / h;
        result += (term * forward_diff[0][i]) / factorial(i);
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
        scanf("%lf%lf", &x[i], &y[i]);
    }
    printf("Enter the target value for forward interpolation: ");
    double target;
    scanf("%lf", &target);

    // Interpolate
    double interpolated_value = newton_forward_difference(x, y, n, target);
    printf("Interpolated value at %lf: %lf\n", target, interpolated_value);

    return 0;
}
