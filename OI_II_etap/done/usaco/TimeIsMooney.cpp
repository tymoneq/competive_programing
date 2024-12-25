#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int n, m, Cost;

    vector<vector<int>> Graf;
    vector<int> Zysk;
    vector<vector<int>> dp;
    int res = 0;
    const int MAXTime = 1010;

public:
    inline void read_data()
    {
        cin >> n >> m >> Cost;
        Graf.resize(n + 1);
        dp.resize(n + 1);
        Zysk.resize(n + 1);

        FOR(i, n + 1, 0)
        dp[i].resize(MAXTime);

        FOR(i, n + 1, 1)
        cin >> Zysk[i];

        FOR(i, m, 0)
        {
            int a, b;
            cin >> a >> b;
            Graf[a].push_back(b);
        }
    }
    inline void solve()
    {
        read_data();

        queue<pair<int, int>> dpKolejka; // first vertex index second time
        dpKolejka.push({1, 0});

        while (!dpKolejka.empty())
        {
            auto v = dpKolejka.front();
            dpKolejka.pop();

            for (int w : Graf[v.first])
            {
                if(v.second+1>= MAXTime)
                    continue;
                if (dp[w][v.second + 1] < dp[v.first][v.second] + Zysk[w])
                {
                    dp[w][v.second + 1] = dp[v.first][v.second] + Zysk[w];
                    if (w != 1)
                        dpKolejka.push({w, v.second + 1});
                    else if (w == 1)
                    {
                        res = max(res, dp[w][v.second + 1] - (Cost * (v.second + 1) * (v.second + 1)));
                        if (dp[w][v.second + 1] - (Cost * (v.second + 1) * (v.second + 1)) > 0)
                            dpKolejka.push({w, v.second + 1});
                    }
                }
            }
        }
        cout << res << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}