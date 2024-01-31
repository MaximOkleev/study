#include <math.h>

unsigned int count_del(unsigned int n)
{
    if (n <= 2)
    {
        return n;
    }
    else if (n == 3)
    {
        return 2;
    }
    unsigned int count = 1;
    int dividers_size = 0;
    int root = (int)sqrt(n) + 1;
    int i = 2;

    while (n > 1 && i <= root)
    {
        while (n % i == 0)
        {
            dividers_size++;
            n /= i;
        }
        ++i;
        count *= dividers_size + 1;
        dividers_size = 0;
    }

    if (n != 1)
        count <<= 1;
    return count;
}


#ifdef MAIN

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE(test_val) (sizeof(test_val) / sizeof(test_val[0]))

int main()
{
    unsigned int test_val[] = {2, 10, 25, 698754321, 687, 100, 90009};
    unsigned int expected[] = {2, 4, 3, 12, 4, 9, 12};
    int cnt_del = 0;

    //assert(ARRAY_SIZE(test_val) == ARRAY_SIZE(expected));
    for (int i = 0; i < ARRAY_SIZE(test_val); i++) 
    {
        assert(count_del(test_val[i]) == expected[i]);
        printf("%x", count_del(test_val[i]));
        //cnt_del = count_del(test_val[i]);
        // printf("[DEBUG] num = %u; count = %u\n", test_val[i], cnt_del);
        /*if (cnt_del == expected[i])
        {
            printf("%d ", cnt_del);
        }*/
    }
    return 0;
}
#endif