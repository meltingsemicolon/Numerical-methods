// Bisection method
#include <stdio.h>
#include <math.h> //to use fabs()

float findfvalue(float x)

{
    float c = x * x * x - x - 4;
    return c;
}

float bisection(float x1, float x2, float E)
{
    int i = 1;
    float x, e;
    while (1)
    {
        x = (x1 + x2) / 2;
        if (findfvalue(x) * findfvalue(x1) < 0)
        {
            x2 = x;
        }
        else if (findfvalue(x) * findfvalue(x2) < 0)
        {
            x1 = x;
        }
        e = fabs((x1 - x2) / x2);
        printf("Iteration count: %d\t Roots:%f\t Error:%f\n", i, x, e);
        i++;

        if (e > E)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return x;
}
float checkvalidity(float x1, float x2)
{
    if (findfvalue(x1) * findfvalue(x2) > 0)
    {
        printf("Invalid roots\n");
        return 1;
    }
    else
    {
        printf("Roots lies between %f and %f\n", x1, x2);
        return 0;
    }
}
int main()
{   int i;
    float x, x1, x2, E;
    do
    {
        printf("Enter lower and upper bound and error limit: ");
        scanf("%f%f%f", &x1, &x2, &E);
    } while (checkvalidity(x1, x2) == 1);

    x = bisection(x1, x2, E);

    printf("Root: %f\t",x);
    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxiteration 18

// Function to evaluate the expression entered by the user
float evaluate_expression(char *expression, float x) {
    // Convert the expression to a function call and evaluate it
    return eval(expression, x); // Assuming you have a function named eval to evaluate expressions
}

// Bisection method
float bisection(char *expression, float x1, float x2) {
    int i = 1;
    float x;
    while (i <= maxiteration) {
        x = (x1 + x2) / 2;
        if (evaluate_expression(expression, x) * evaluate_expression(expression, x1) < 0) {
            x2 = x;
        } else if (evaluate_expression(expression, x) * evaluate_expression(expression, x2) < 0) {
            x1 = x;
        }
        printf("Iteration count: %d\t Root: %f\n", i, x);
        i++;
    }
    return x;
}

// Check validity of roots
int checkvalidity(char *expression, float x1, float x2) {
    if (evaluate_expression(expression, x1) * evaluate_expression(expression, x2) > 0) {
        printf("Invalid roots\n");
        return 1;
    } else {
        printf("Roots lie between %f and %f\n", x1, x2);
        return 0;
    }
}

int main() {
    char expression[100];
    float x, x1, x2;

    printf("Enter the expression (e.g., sin(x)): ");
    fgets(expression, sizeof(expression), stdin);

    do {
        printf("Enter lower and upper bound: ");
        scanf("%f%f", &x1, &x2);
    } while (checkvalidity(expression, x1, x2) == 1);

    x = bisection(expression, x1, x2);

    printf("Root: %f\n", x);
    return 0;
}
*/