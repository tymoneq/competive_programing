#include <bits/stdc++.h>

using namespace std;

long long fast_pot(long long n, long long w)
{
    int a = 1;
    while (w > 0)
    {
        if (w % 2 == 1)
            a *= n;

        a *= a;
        w /= 2;
    }
    return a;
}

int main()
{

    long long n, w; // n= podstawa w = wyznacznik
    cin >> n >> w;
    cout << fast_pot(n, w);
}