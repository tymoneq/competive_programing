#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll N, d;
ull a, b;

unordered_map<ll, ull> dp;

inline ull f(ull w, ull v) { return (a * w + b * v) % 1001; }

void calc(ll left, ll right)
{
    ll newleft = (left - d + 1) / 2;
    ll newRight = (right + d) / 2;
    // rekurencja
    if (left >= d)
        calc(newleft, newRight);

    if (left < d && left > 1)
        calc(1, newRight);

    // Obliczanie wyniku
    for (ll i = max(left, (ll)2); i <= right; i++)
    {
        if (dp.find(i) != dp.end())
            continue;
        dp[i] = numeric_limits<ull>::max();
        for (ll j = max(newleft, (ll)1); j <= newRight; j++)
        {
            ll x = i - j;
            if (abs(x - j) > d)
                continue;

            if (x <= 0)
                break;

            ull mn = min(f(x, j), f(j, x)) + dp[x] + dp[j];
            dp[i] = min(dp[i], mn);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> d >> a >> b;

    dp[0] = 0, dp[1] = 0;

    calc(N, N);

    cout << dp[N] << "\n";
    return 0;
}