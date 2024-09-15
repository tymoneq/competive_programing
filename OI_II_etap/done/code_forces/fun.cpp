#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t, n, x;
    ll ans = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        ans = 0;

        for (ll a = 1; a <= n; a++)
            for (ll b = 1; b * a <= n; b++)
            {
                ll ub = min((n - (a * b)) / (a + b), x - a - b);
                if (ub >= 1)
                    ans += ub;
            }
        cout << ans << "\n";
    }

    return 0;
}