#ifdef MAIN

#include <stdio.h>
#include <assert.h>
#include <math.h>

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

typedef struct point p;

typedef struct test_item_s test_item_t;

//#define ARRAY_SIZE(x) (sizeof(test_val) / sizeof(test_val[0]))

int main()
{
    int n = 0;
    unsigned int size = 0;
    int *dividers = NULL;

    //unsigned int test_val[] = {1, 2, 10, 25, 121};

    p expected[] = {
        { .x1 = 1, .y1 = 2, .x2 = 2, .y2 = 3 },
        { .x1 = 2, .y1 = 3, .x2 = 3, .y2 = 4 },
        { .x1 = 3, .y1 = 4, .x2 = 4, .y2 = 5 },
        { .x1 = 4, .y1 = 5, .x2 = 5, .y2 = 6 },
        { .x1 = 5, .y1 = 6, .x2 = 6, .y2 = 7 }
    };

    for (int i = 0; i < 5; i++)
    {
        printf("%f ", sqrt((expected[i].x1 - expected[i].x2) * (expected[i].x1 - expected[i].x2) + (expected[i].y1 - expected[i].y2) * (expected[i].y1 - expected[i].y2)));
    }

    /*test_item_t expected[] = {
        { .size = 1, .arr = {1} },
        { .size = 2, .arr = {1, 2} },
        { .size = 4, .arr = {1, 2, 5, 10} },
        { .size = 3, .arr = {1, 5, 25} },
        { .size = 3, .arr = {1, 11, 121} }
    };*/

}

#endif
