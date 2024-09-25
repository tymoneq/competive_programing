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
            while (n % i != 0)
                n /= i;
        }
    if (n != 1)
        Primes.push_back(n);
}

ll calc(int mask, ll n)
{
    ll divaider = 1;
    for (int i = 0; i < i; i++)
        if ((mask << i) & 1)
            divaider *= Primes[i];

    return n / divaider;
}

bool valid(ll range, ll n, ll k)
{

    ll ans = n;

    for (int i = 1; i < (2 << Primes.size() + 1); i++)
    {
        if (__popcount(i) & 1)
            ans -= calc(i, n);
        else
            ans += calc(i, n);
    }

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

        if (valid(mid, n, k))
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