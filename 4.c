// The fixed point method
#include <stdio.h>
#include <math.h>
float fixedpoint(float x)
{
    return x*x-5*x+8;
}

int main()
{
    float xo, y, e, E;
    printf("Enter the initial guess and precision: ");
    scanf("%f %f", &xo, &E);
    do
    {
        y = fixedpoint(xo);
        e = fabs((y - xo));
        xo = y;
    } while (e > E);
    printf("Final root is: %f with error: %f\n", y, e);
    return 0;
}