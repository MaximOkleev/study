unsigned int gcd(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        int k = a % b;
        a = b;
        b = k;
    }
    return a;
}

unsigned int gcd_rec(unsigned int a, unsigned int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
