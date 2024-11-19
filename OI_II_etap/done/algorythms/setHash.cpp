#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int K = 107, H = 881, MOD = 1e9 + 123;

unordered_map<int, ll> Hash;

ll pot(ll a, ll n)
{
    long long w = 1;

    while (n > 0)
    {
        if (n % 2 == 1) // jesli bit jest = 1
            w *= a;

        a *= a;
        n /= 2; // skrócenie o jeden bit
        w %= MOD;
        a %= MOD;
    }
    return w;
}

ll hasging(int a)
{
    ll hash = (a + K);
    hash = pot(hash, H);

    return hash;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for every element in set hash it and add hash to map 

    return 0;
}