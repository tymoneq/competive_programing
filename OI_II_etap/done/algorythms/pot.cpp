const int mod = 1e9 + 7;

int pot(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b % 2 == 0)
    {
        long long pom;
        pom = pot(a, b / 2);
        return (pom * pom) % mod;
    }
    else
    {
        return a * pot(a, b - 1) % mod;
    }
}