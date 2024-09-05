//Three Point Difference Formula
#include <stdio.h>
#include <math.h>
#define f(x) (x*x*exp(x))
int main() 
{
    float h, x, d;
    printf("Enter the value at which derivative is required: ");
    scanf("%f", &x);
    printf("Enter the value of h: ");
    scanf("%f", &h);
    d = (f(x + h/2) - f(x - h/2)) / h;
    printf("Value of Derivative = %f\n", d);
    return 0;
}
