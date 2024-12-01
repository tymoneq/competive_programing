#include <bits/stdc++.h>

using namespace std;

inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs) { return lhs.second < rhs.second; }

inline void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> Shops(n);

    for (auto &el : Shops)
    {
        cin >> el.first >> el.second;
    }

    sort(Shops.begin(), Shops.end(), sorto);

    int lo = 0, hi = Shops.size() - 1, ans = numeric_limits<int>::max(), mid;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        int mxCost = 0;
        pair<int, int> tmp = {0, numeric_limits<int>::max()};
        for (int i = 0; i < n; i++)
        {
            if (mid == i)
                continue;
            if (Shops[i].second <= Shops[mid].second)
            {
                if (Shops[i].first <= Shops[mid].second)
                    tmp.first = max(tmp.first, Shops[i].first);

                else
                    tmp.second = max(tmp.second, Shops[i].first);
            }
            else
                mxCost = max(Shops[i].first, mxCost);
        }

        if (mxCost == 0)
        {
            if (Shops[mid].second - tmp.first <= tmp.second - Shops[mid].second)
                mxCost = tmp.first;
            else
                mxCost = tmp.second;
        }

        ans = min(ans, abs(Shops[mid].second - mxCost));

        if (mxCost > Shops[mid].second)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}