#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAXN = 1e6 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    ll a, g = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        g = __gcd(g, a);
    }
    for (ll i = 1; i * i <= g; i++)
        if (g % i == 0)
        {
            ans++;
            if (i != g / i)
                ans++;
        }

    cout << ans << "\n";
    return 0;
}