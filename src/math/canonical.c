#include <sys/types.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int *canonical(unsigned int n, int *size)
{
    int dividers_size = 1;
    int* dividers = (int*)malloc(dividers_size * sizeof(int));
    int root = (int)sqrt(n) + 1;
    int i = 2;

    if (!dividers)
        return NULL;

    dividers[0] = 1;
    while (n > 1 && i <= root)
    {
        while (n % i == 0)
        {
            dividers = (int*)realloc(dividers, dividers_size + 1);
            if (!dividers)
                return NULL;
            dividers[dividers_size] = i;
            dividers_size++;
            n /= i;
        }
        ++i;
    }
    if (n != 1)
    {
        dividers = (int*)realloc(dividers, dividers_size + 1);
        if (!dividers)
            return NULL;
        dividers[dividers_size] = n;
        dividers_size++;
    }
    *size = dividers_size;
    return dividers;
}

#ifdef MAIN

#include <stdio.h>

int main()
{
    int n = 0;
    int size = 0;
    int *dividers = NULL;

    long long test_val[] = {-10, -56, -1, 0, 2, 10, 25, 698754321, 687, 100, 90009};
    long long expected[] = {-1, -65, -1, 0, 2, 1, 52, 123457896, 786, 1, 90009};
    
    for (int i = 0; i < ARRAY_SIZE(test_val); i++) 
    {
        assert(print_reverse_num(test_val[i]) == expected[i]);
    }
    dividers = canonical(n, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", dividers[i]);
    }
}
#endif