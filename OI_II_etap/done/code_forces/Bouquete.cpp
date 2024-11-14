#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int binarSearch(vector<pair<ll, ll>> &flowers, ll val)
{
    int lo = 0, hi = flowers.size() - 1, mid;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if (flowers[mid].first == val)
            return mid;

        else if (flowers[mid].first > val)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return -1;
}

inline void solve()
{
    int n;
    ll m;
    cin >> n >> m;
    vector<pair<ll, ll>> flowers(n);
    vector<pair<ll, ll>> flowers2;
    for (auto &a : flowers)
        cin >> a.first;

    for (auto &a : flowers)
        cin >> a.second;

    sort(flowers.begin(), flowers.end());
    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        int indx = binarSearch(flowers2, flowers[i].first);
        if (indx == -1)
            flowers2.push_back(flowers[i]);

        else
            flowers2[indx].second += flowers[i].second;
    }

    for (int i = 0; i < flowers2.size(); i++)
    {
        if (i == n - 1 || (i != n - 1 && flowers2[i + 1].first - 1 != flowers2[i].first))
        {
            ll tmp = flowers2[i].first * min(flowers2[i].second, (m / flowers2[i].first));
            res = max(res, tmp);
        }
        else if (i != n - 1 && flowers2[i + 1].first - 1 == flowers2[i].first)
        {
            ll tmp = flowers2[i].first * min(flowers2[i].second, (m / flowers2[i].first));
            res = max(res, tmp);

            // mogę wziąć wszystkie lepsze kwiaty
            if (flowers2[i + 1].second * flowers2[i + 1].first <= m)
            {
                tmp = flowers2[i + 1].second * flowers2[i + 1].first;
                ll secondTypeCount = (m - tmp) / flowers2[i].first;
                res = max(res, tmp + (min(secondTypeCount, flowers2[i].second))*flowers2[i].first);
            }
            // nie mogę wziąć wszystkich lepszych kwiatów
            else
            {
                tmp = (m / flowers2[i + 1].first);
                ll secondTypeCount = (m - tmp) / flowers2[i].first;
                res = max(res, tmp * flowers2[i + 1].first + min(secondTypeCount, flowers2[i].second)*flowers2[i].first);
            }
        }
    }

    cout << res << '\n';
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