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

#define ARRAY_SIZE(x) (sizeof(test_val) / sizeof(test_val[0]))

int main()
{
    int n = 0;
    unsigned int size = 0;
    int *dividers = NULL;

    int test_val[][] = {{1, 2, 2, 3}, {2, 3, 3, 4}, {3, 4, 4, 5}, {4, 5, 5, 6}, {5, 6, 6, 7}};

    p expected[] = {
        { .x1 = 1, .y1 = 2, .x2 = 2, .y2 = 3 },
        { .x1 = 2, .y1 = 3, .x2 = 3, .y2 = 4 },
        { .x1 = 3, .y1 = 4, .x2 = 4, .y2 = 5 },
        { .x1 = 4, .y1 = 5, .x2 = 5, .y2 = 6 },
        { .x1 = 5, .y1 = 6, .x2 = 6, .y2 = 7 }
    };

    for (int i = 0; i < 5; i++)
    {
        double s = sqrt((expected[i].x1 - expected[i].x2) * (expected[i].x1 - expected[i].x2) + (expected[i].y1 - expected[i].y2) * (expected[i].y1 - expected[i].y2));
        double k = sqrt((test_val[i][0] - test_val[i][2]) * (test_val[i][0] - test_val[i][2]) + (test_val[i][1] - test_val[i][3]) * (test_val[i][1] - test_val[i][3]));
        assert(s == k);
        printf("%f", s);
    }
}

#endif
