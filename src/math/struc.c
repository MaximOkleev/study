#ifdef MAIN

#include <stdio.h>
#include <assert.h>
#include <math.h>

struct doubl
{
    double x;
    double y;
};

struct point
{
    int x1;
    int y1;
    int x2;
    int y2;
};

struct test_item_s
{
    size_t size;
    unsigned int arr[10];
};

typedef struct doubl d;

typedef struct point p;

typedef struct test_item_s test_item_t;

//#define ARRAY_SIZE(x) (sizeof(test_val) / sizeof(test_val[0]))

int main()
{
    int n = 0;
    unsigned int size = 0;
    int *dividers = NULL;

    double test_val[][] = {{1.2, 1.3}, {1.3, 1.4}, {1.4, 1.5}, {1.5, 1.6}, {1.6, 1.7}};

    d expected[] = {
        { .x = 1.2, .y = 1.3 },
        { .x = 1.3, .y = 1.4 },
        { .x = 1.4, .y = 1.5 },
        { .x = 1.5, .y = 1.6 },
        { .x = 1.6, .y = 1.7 }
    };

    for (int i = 0; i < 5; i++)
    {
        assert((expected[i].x + expected[i].y) == test_val[i][0] + test_val[i][1]);
        assert((expected[i].x - expected[i].y) == test_val[i][0] - test_val[i][1]);
        assert((expected[i].x * expected[i].y) == test_val[i][0] * test_val[i][1]);
        printf("%f %f %f", expected[i].x + expected[i].y, expected[i].x - expected[i].y, expected[i].x * expected[i].y);
    }
}

#endif