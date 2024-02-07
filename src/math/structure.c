#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

struct point
{
    int x;
    int y;
};
typedef struct point point_t;

typedef struct line
{
    point_t p1;
    point_t p2;
} line_t;

double line_length(line_t l) // struct line l
{
    return sqrt((l.p1.x - l.p2.x) * (l.p1.x - l.p2.x) + (l.p1.y - l.p2.y) * (l.p1.y - l.p2.y));
}

double distance_between_two_points(point_t p1, point_t p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double distance_between_two_points_coord(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


#define ARRAY_SIZE(x) (sizeof(test_val) / sizeof(test_val[0]))

#ifdef MAIN

int main()
{
    int n = 0;
    unsigned int size = 0;
    int *dividers = NULL;
    double eps = 0.000001;

    point_t test_val[][2] = {
        { {1, 2}, {2, 3} },
        { {2, 3}, {3, 4} },
        { {3, 4}, {4, 5} },
        { {4, 5}, {5, 6} },
        { {5, 6}, {6, 7} }
    };

    double expected[] = {
        1.414214, 1.414214, 1.414214, 1.414214, 1.414214
    };

    for (int i = 0; i < 5; i++)
    {
        double s = distance_between_two_points(test_val[i][0], test_val[i][1]);
        printf("%lf: delta = %.12lf\n", s, s - expected[i]);
        assert(fabsl(s - expected[i]) <= eps);
    }
}

#endif
