#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

struct arithmetic_operations_with_two_double
{
    double x;
    double y;
};

typedef struct arithmetic_operations_with_two_double oper_double;

double summation_two_double(oper_double a, oper_double b)
{
    return a.x + b.y;
}

double subtraction_two_double(oper_double a, oper_double b)
{
    return fabsl(a.x - b.y);
}

double product_of_two_double(oper_double a, oper_double b)
{
    return a.x * b.y;
}

#define ARRAY_SIZE(x) (sizeof(test_val) / sizeof(test_val[0]))

#ifdef MAIN

int main()
{
    int n = 0;
    unsigned int size = 0;
    int *dividers = NULL;
    double eps = 0.000001;

    oper_double test_val[][2] = {
        { 1.2, 1.3 }, 
        { 1.3, 1.4 },
        { 1.4, 1.5 },
        { 1.5, 1.6 }, 
        { 1.6, 1.7 }
    };

    double expected[][3] = {
        { 2.5, 0.1, 1.56 },
        { 2.7, 0.1, 1.82 },
        { 2.9, 0.1, 2.1 },
        { 3.1, 0.1, 2.4 },
        { 3.3, 0.1, 2.72 }
    };

    for (int i = 0; i < 5; i++)
    {
        double sum = summation_two_double(test_val[i][0], test_val[i][1]);
        double sub = subtraction_two_double(test_val[i][0], test_val[i][1]);
        double prod = product_of_two_double(test_val[i][0], test_val[i][1]);
        printf("%lf %lf %f \n", sum, sub, prod);
        assert(fabsl(sum - expected[i][0]) <= eps);
        assert(fabsl(sub - expected[i][1]) <= eps);
        assert(fabsl(prod - expected[i][2]) <= eps);
    }
}

#endif
