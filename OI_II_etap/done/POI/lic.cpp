#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> Primes;

void to_prime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            Primes.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    if (n != 1)
        Primes.push_back(n);
}

ll calc(int mask, ll n)
{
    ll divaider = 1;
    for (int i = 0; i < Primes.size(); i++)
        if ((mask >> i) & 1)
            divaider *= Primes[i];

    return n / divaider;
}

bool valid(ll range, ll k)
{

    ll ans = range;
    ll others = 0;
    for (int i = 1; i < (1 << Primes.size()); i++)
    {
        if (__builtin_popcount(i) & 1)
            others += calc(i, range);
        else
            others -= calc(i, range);
    }
    ans -= others;
    return ans >= k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k, c;
    cin >> n >> k >> c;
    to_prime(n);

    ll lo = 1, hi = 5e16, mid, ans;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if (valid(mid, k))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    c--;
    cout << ans << " ";
    while (c > 0)
    {
        ans++;
        if (__gcd(n, ans) == 1)
        {
            cout << ans << " ";
            c--;
        }
    }
    cout << "\n";

    return 0;
}