// Netwon rapson method
#include <stdio.h>
#include <math.h>

float f(float x)
{
    float c = (x * x * x - 2 * x * x + 12 * x + 2);
    printf("function value : %f\t", c);
    return c;
}
float fd(float x)
{
    float c = 3 * x * x - 4 * x + 12;
    printf("Derivative value: %f\t", c);
    return c;
}
float newassumption(float x)
{
    float y = x + (f(x) / fd(x));
    printf("newasumption: %f\t", y);
    return y;
}

int main()
{
    double x, y, e, E;
    printf("Enter initial guess and precision: ");
    scanf("%f%f", &x, &E);
    y = newassumption(x);
    e = fabs((y - x) / x);
    if (e > E)
    {
        x = y;
        printf("\n");
        newassumption(x);
    }
    printf("\nThe final root is: %f", y);
    return 0;
}
