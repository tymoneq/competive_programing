#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    ll x;
    pair<ll, ll> Res = {numeric_limits<ll>::max(), numeric_limits<ll>::max()};
    cin >> x;

    for (ll i = 1; i * i <= x; i++)
        if (x % i == 0)
        {
            ll b = x / i;
            if (i * b / __gcd(i, b) == x && max(i, b) < max(Res.first, Res.second))
                Res = {i, b};
        }

    cout << Res.first << " " << Res.second << "\n";
    return 0;
}