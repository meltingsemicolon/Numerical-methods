//Newton's Divided Difference Formula for Unequal Interval
#include <stdio.h>
double factorial(int n) 
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
double newtonsDividedDifference(double (*func)(double), double *x, double *y, int n) 
{
    double result = 0.0;
	int i,j;
    for ( i = 0; i < n; i++) 
	{
        double term = y[i];
        for ( j = 0; j < i; j++) 
		{
            term = term / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}
double exampleFunction(double x) 
{
    return x * x;
}
int main() 
{
	int n = 3;
    double x[] = {1.0, 2.0, 3.0};
    double y[] = {1.0, 4.0, 9.0};
    double dividedDifference = newtonsDividedDifference(exampleFunction, x, y, n);
    printf("Newton's Divided Difference:\n The first derivative at x = %.2f is approximately %.2f\n", x[0], dividedDifference);
    return 0;
}
