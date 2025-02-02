#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)
typedef long long ll;

class Solve
{
protected:
    int N, M;
    int maxMask;

    const ll INF = 1e18;
    vector<vector<ll>> Planety;
    vector<ll> dp;

    vector<ll> pom;
    vector<ll> Wartosci;

public:
    inline void read_data()
    {
        cin >> N >> M;

        Planety.resize(N + 1, vector<ll>(M));
        dp.resize(N + 1, -INF);

        maxMask = 1 << M;

        Wartosci.resize(maxMask, 0);
        pom.resize(maxMask, -INF);

        FOR(i, N + 1, 1)
        FOR(j, M, 0)
        cin >> Planety[i][j];
    }

    inline void solve()
    {
        read_data();

        dp[0] = dp[1] = 0;
        FOR(i, N + 1, 1)
        {
            FOR(mask, maxMask, 0)
            {
                Wartosci[mask] = 0;
                FOR(bit, M, 0)
                {
                    if (mask & (1 << bit))
                        Wartosci[mask] += Planety[i][bit];
                    else
                        Wartosci[mask] -= Planety[i][bit];
                }
            }

            FOR(mask, maxMask, 0)
            dp[i] = max({pom[mask] + Wartosci[mask], dp[i], dp[i - 1]});

            FOR(mask, maxMask, 0)
            pom[mask] = max(pom[mask], dp[i - 1] - Wartosci[mask]);
        }

        cout << dp[N] << '\n';
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