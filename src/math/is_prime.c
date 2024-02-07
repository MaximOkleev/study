#include <math.h>

int is_prime(unsigned long long num)
{
    if (num < 2)
        return 0;
    if (num == 2 || num == 3 || num == 5)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;

    for (unsigned long long i = 5; i <= sqrtl(num); i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;
}

#ifdef MAIN

#include <stdio.h>

#define SIZE_ARR(x) (sizeof(x) / sizeof(x[0]))

int main()
{
    unsigned long long test_val[] = { 0, 1, 2, 3, 5, 10, 55, 49, 17 * 19, 121, 127 }; // 28 bytes
    unsigned long long expected[] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1};
    
    for (int i = 0; i < ARRAY_SIZE(test_val); i++) 
    {
        assert(print_reverse_num(test_val[i]) == expected[i]);
    }
    return 0;
}
#endif
