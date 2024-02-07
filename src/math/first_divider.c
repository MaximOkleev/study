#include <math.h>

unsigned long long first_divider(unsigned long long n)
{
    unsigned long long i = 2;

    for(; i <= sqrtl(n); i++)
        if (n % i == 0)
            return i;
    return i;
}

#ifdef MAIN

#include <stdio.h>

#define SIZE_ARR(x) (sizeof(x) / sizeof(x[0]))

int main()
{
    unsigned long long nums[] = { 0, 1, 2, 3, 10, 55, 49, 17 * 19 }; // 28 bytes

    for (int i = 0; i < SIZE_ARR(nums); ++i)
    {
        printf("First divider of %llu is equal %llu\n", nums[i], first_divider(nums[i]));
    }
    return 0;
}
#endif
