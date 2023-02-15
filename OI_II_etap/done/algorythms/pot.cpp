const int mod = 1e9 + 7;

long long pot_szybkie(long long a, unsigned int n)
{
    long long w = 1;

    while (n > 0)
    {
        if (n % 2 == 1) // jesli bit jest = 1
            w *= a;

        a *= a;
        n /= 2; // skrócenie o jeden bit
    }
    return w;
}