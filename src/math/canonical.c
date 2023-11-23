#include <sys/types.h>
#include <math.h>
#include <stdlib.h>

// typedef unsigned int u_int32_t;

// 180
// [1 2 2 3 3 5]
// size = 6
// int array[4] = {0, 1, 2, 56};
// malloc, calloc, realloc
// free
/////////////////////// vector<int> a(10, 0);

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
//gcc -DMAIN -o bin/canonical src/math/canonical.c -lm

#ifdef MAIN

#include <stdio.h>

int main()
{
    int n = 0;
    int size = 0;
    int *dividers = NULL;

    scanf("%d", &n);
    dividers = canonical(n, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", dividers[i]);
    }
}

#endif