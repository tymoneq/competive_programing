#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, n, a, mx;
    map<ll, ll> M;
    ll k, ans;
    cin >> t;

    while (t--)
    {
        M.clear();
        mx = 0;
        cin >> n >> k;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a % k == 0)
                continue;

            ++M[k - a % k];
            mx = max(mx, M[k - a % k]);
        }
        for (auto el : M)
            if (el.second == mx)
                ans = k * (el.second - 1) + el.first + 1;
        cout << ans << "\n";
    }

    return 0;
}