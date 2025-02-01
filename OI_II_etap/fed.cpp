#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    int N;
    ll res = 0;
    ll all_cost = 0;

    const int States = 2;

    struct edge
    {
        ll to, cost;
    };

    vector<vector<edge>> Galaktyka;

    vector<vector<ll>> dp;

public:
    inline void read_data()
    {
        cin >> N;

        Galaktyka.resize(N + 1);

        dp.resize(N + 1, vector<ll>(States));

        FOR(i, N, 1)
        {
            ll from, to, cost;
            cin >> from >> to >> cost;

            Galaktyka[from].push_back({to, cost});
            Galaktyka[to].push_back({from, cost});
        }
    }

    inline void calc_dp(int v, int p)
    {

        ll kraw_ojca = 0;
        for (auto w : Galaktyka[v])
        {
            if (w.to != p)
                calc_dp(w.to, v);

            if (w.to == p)
                kraw_ojca = w.cost;
        }

        if (v != p)
        {
            for (auto w : Galaktyka[v])
                if (w.to != p)
                {
                    dp[v][0] += max(dp[w.to][0], dp[w.to][1]);
                    dp[v][1] += max(dp[w.to][0], dp[w.to][1]);
                }
            ll max_zysk = 0;

            for (auto w : Galaktyka[v])
                if (w.to != p)
                    max_zysk = max(dp[w.to][0] + w.cost + kraw_ojca - max(dp[w.to][0], dp[w.to][1]), max_zysk);

            dp[v][1] += max_zysk;
        }
        else
        {
            for (auto w : Galaktyka[v])
                if (w.to != p)
                {
                    dp[v][0] += max(dp[w.to][0], dp[w.to][1]);
                    dp[v][1] += max(dp[w.to][0], dp[w.to][1]);
                }

            ll max_zysk = 0;

            for (auto w : Galaktyka[v])
                if (w.to != p)
                    for (auto u : Galaktyka[v])
                        if (u.to != w.to && u.to != p)
                            max_zysk = max(dp[w.to][0] + w.cost + u.cost + dp[u.to][0] - max(dp[w.to][0], dp[w.to][1]) - max(dp[u.to][0], dp[u.to][1]), max_zysk);

            dp[v][1] += max_zysk;
        }
    }

    inline void solve()
    {
        read_data();

        FOR(i, N + 1, 1)
        {

            FOR(j, N + 1, 1)
            dp[j][1] = dp[j][0] = 0;

            calc_dp(i, i);

            res = max({res, dp[i][0], dp[i][1]});
        }

        cout << res << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve s;
    s.solve();

    return 0;
}