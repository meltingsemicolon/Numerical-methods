// The secant method
#include <stdio.h>
#include <math.h>
float fvalue(float X)
{
    float c = (X * X * X - 3 * X - 12);
    return c;
}
float secant(float a, float b)
{
    float n;
    n = b - (fvalue(b) * (b - a)) / (fvalue(b) - fvalue(a));
    printf("Root is: %f\t", n);
    return n;
}

int main()
{
    float x, y, z, e, E;
    printf("Enter the inital guess such that x < y and precision: ");
    scanf("%f %f %f", &x, &y, &E);
    do
    {
        z = secant(x, y);
        e = fabs((z - y) / z);
        printf("Error is: %f\n",e);
        x = y;
        y = z;
    } while (e > E);
    printf("Final root is: %f\t  With error: %f", z, e);
    return 0;
}