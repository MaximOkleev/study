#include <math.h>
#include <stdlib.h>

unsigned int *canonical(unsigned int n, int *size)
{
    int dividers_size = 1;
    unsigned int* dividers = (unsigned int*)malloc(dividers_size * sizeof(unsigned int));
    int root = (int)sqrt(n) + 1;
    int i = 2;

    if (!dividers)
        return NULL;

    dividers[0] = 1;
    while (n > 1 && i <= root)
    {
        while (n % i == 0)
        {
            dividers = (unsigned int*)realloc(dividers, dividers_size + 1);
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
        dividers = (unsigned int*)realloc(dividers, dividers_size + 1);
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
#include <assert.h>

struct test_item_s
{
    size_t size;
    unsigned int arr[10];
};

typedef struct test_item_s test_item_t;

#define ARRAY_SIZE(x) (sizeof(test_val) / sizeof(test_val[0]))

int main()
{
    int n = 0;
    unsigned int size = 0;
    unsigned int *dividers = NULL;

    unsigned int test_val[] = {1, 2, 10, 25, 121};
    // long long expected[5][2][4] = {{{1}, {1}}, {{2}, {1, 2}}, {{4}, {1, 2, 5, 10}}, {{3}, {1, 5, 25}}, {{3}, {1, 11, 121}}};

    // struct test_item_s expected[] = {};
    test_item_t expected[] = {
        { .size = 1, .arr = {1} },
        { .size = 2, .arr = {1, 2} },
        { .size = 3, .arr = {1, 2, 5} },
        { .size = 3, .arr = {1, 5, 5} },
        { .size = 3, .arr = {1, 11, 11} }
    };
    /*dividers = canonical(test_val[0], &size);
    for(int i = 0; i < size; i++)
    {
        printf("%u ", dividers[i]);
    }*/
    for (int i = 0; i < ARRAY_SIZE(test_val); i++) 
    {
        dividers = canonical(test_val[i], &size);
        assert(size == expected[i].size);
        for(int j = 0; j < size; j++)
        {
            assert(dividers[j] == expected[i].arr[j]);
            printf("%u ", dividers[j]);
        }
        printf("\n");
    }
}
#endif