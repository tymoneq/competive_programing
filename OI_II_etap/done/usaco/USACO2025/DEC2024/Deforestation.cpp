#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

constexpr int INF = 1e9 + 5;
struct range
{
    int l, r, t;
};

inline bool sorto(vector<int> &lhs, vector<int> &rhs)
{
    return lhs.size() > rhs.size();
}
inline bool sorto0(range &lhs, range &rhs)
{
    if (lhs.l == rhs.l)
        return rhs.r < rhs.r;
    return rhs.l < rhs.l;
}

inline void s(vector<range> Ranges, vector<int> Trees)
{
    sort(Ranges.begin(), Ranges.end(), sorto0);
    sort(Trees.begin(), Trees.end());

    int cnt = 0;
    bool closed = 1;
    int end_range = INF;
    for (auto w : Ranges)
    {
        if (w.l > end_range)
        {
            closed = 1;
            cnt++;
            end_range = w.r;
        }
        else if (w.l < end_range)
        {
            end_range = min(end_range, w.r);
        }
    }

    cout << Trees.size() - cnt << '\n';
}

inline void solve()
{

    int n, k, res = 0;
    cin >> n >> k;
    vector<int> Trees;
    bool special = 1;
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        Trees.push_back(w);
    }
    vector<range> Ranges(k);
    for (auto &w : Ranges)
    {
        cin >> w.l >> w.r >> w.t;
        if (w.t != 1)
            special = 0;
    }
    if (special)
    {
        s(Ranges, Trees);
    }
    else
    {
        vector<vector<int>> points(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                if (Ranges[j].l <= Trees[i] && Ranges[j].r >= Trees[i])
                    points[i].push_back(j);

        sort(points.begin(), points.end());

        for (int i = 0; i < n; i++)
        {
            bool c = 1;
            for (int w : points[i])
            {
                if (Ranges[w].t == 0)
                    continue;

                c = 0;
                Ranges[w].t--;
            }

            if (c)
                res++;
        }
        cout << res << '\n';
    }
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
