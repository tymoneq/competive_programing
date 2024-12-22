#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    int n, m, k, maxMask;

    vector<vector<ll>> dp;
    vector<int> Fotogenicznosc;
    vector<int> Krawedzie;
    vector<ll> ANS;

public:
    inline void solve()
    {
        cin >> n >> m >> k;
        dp.resize(2);
        Krawedzie.resize(n + 1);
        Fotogenicznosc.resize(n + 1);
        ANS.resize(n + 1);

        maxMask = 1 << (k + 1);
        FOR(i, 2, 0)
        dp[i].resize(1 << (k + 1));

        FOR(i, n + 1, 1)
        cin >> Fotogenicznosc[i];

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            Krawedzie[a] |= (1 << (b - a));
        }

        for (int i = n; i > 0; i--)
        {
            FOR(mask, maxMask, 0)
            {
                if (mask % 2 == 1)
                    dp[0][mask] = dp[1][(mask >> 1) | (Krawedzie[i]>>1)] + Fotogenicznosc[i];

                else
                    dp[0][mask] = dp[1][mask >> 1];
            }

            ANS[i] = dp[0][Krawedzie[i] | 1];
            dp[1] = dp[0];

            FOR(mask, maxMask, 0)
            dp[0][mask] = 0;
        }

        FOR(i, n + 1, 1)
        cout << ANS[i] << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve solution;
    solution.solve();

    return 0;
}