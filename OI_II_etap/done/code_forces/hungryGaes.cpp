#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        partial_sum(a.begin() + 1, a.end(), a.begin() + 1);
        vector<int> dp(n + 2);
        for (int i = n - 1; i >= 0; --i)
        {
            int q = upper_bound(a.begin(), a.end(), a[i] + x) - a.begin();
            dp[i] = dp[q] + q - i - 1;
        }
        cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n';
    }

    return 0;
}