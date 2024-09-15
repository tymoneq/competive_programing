#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr ll MAXN = 1e12;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, n, h;
    cin >> t;

    while (t--)
    {
        cin >> h >> n;

        vector<pair<ll, ll>> Attacks(n);

        for (auto &p : Attacks)
            cin >> p.first;
        for (auto &p : Attacks)
            cin >> p.second;

        ll ans = 0, l = 1, r = MAXN, mid, sum;

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            sum = 0;
            for (auto el : Attacks)
            {
                sum += (((mid - 1) / el.second) + 1) * el.first;
                if (sum > h)
                    break;
            }

            if (sum < h)
                l = mid + 1;
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}