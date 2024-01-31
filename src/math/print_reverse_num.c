#include <math.h>

long long return_reverse_num(long long n)
{
    long long a = 0;
    
    while (n != 0)
    {
        a = 10 * a + n % 10;
        n /= 10;
    }
    return a;
}

#ifdef MAIN

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

int main()
{
    long long test_val[] = {-10, -56, -1, 0, 2, 10, 25, 698754321, 687, 100, 90009};
    long long expected[] = {-1, -65, -1, 0, 2, 1, 52, 123457896, 786, 1, 90009};
    
    for (int i = 0; i < ARRAY_SIZE(test_val); i++) 
    {
        assert(return_reverse_num(test_val[i]) == expected[i]);
    }
    return 0;
}

#endif