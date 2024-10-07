#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;

    cin >> n;
    vector<ll> a(n);
    for (ll &r : a)
        cin >> r;

    ll res = 0;
    sort(a.begin(), a.end());
    do
    {
        bool T = 1;
        ll mx = a[0];
        for (int i = 1; i < n; i++)
        {
            if ((a[i] >= 2 * mx) || (2 * a[i] <= mx))
                mx = max(mx, a[i]);
            else
            {
                T = 0;
                break;
            }
        }
        if (T)
            ++res;
        res %= MOD;
    } while (next_permutation(a.begin(), a.end()));

    cout << res << "\n";

    return 0;
}