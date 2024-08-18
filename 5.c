// horner's method
#include <stdio.h>
#include <stdlib.h>

double calculate_expression(double *arr, int size, double x) {
    double result = 0;
    int i;
    double power_of_x = 1; // Initialize to x^0

    for (i = 0; i <= size; i++) {
        result += arr[i] * power_of_x;
        power_of_x *= x; // Update power_of_x for the next term
    }

    return result;
}

int main() {
    int size;
    printf("expression is (for i=0 to i= degree) sum of ai*x^i\n");
    printf("Enter degree of expression : ");
    scanf("%d", &size);

    double *coefficients = (double *)malloc(size * sizeof(double));
    if (coefficients == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Enter the coefficients:\n");
    for (int i = 0; i <= size; i++) {
        scanf("%lf", &coefficients[i]);
    }

    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    double result = calculate_expression(coefficients, size, x);
    printf("Result of the expression: %lf\n", result);

    free(coefficients); // Free dynamically allocated memory

    return 0;
}
