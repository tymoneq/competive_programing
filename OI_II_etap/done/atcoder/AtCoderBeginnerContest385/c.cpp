#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int n;
    vector<int> Wartosci;
    vector<vector<int>> dp;

public:
    inline void solve()
    {

        cin >> n;
        Wartosci.resize(n);
        dp.resize(n);

        FOR(i, n, 0)
        {
            cin >> Wartosci[i];
            dp[i].resize(n + 10, 1);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            FOR(j, n + 1, 1)
            {
                if (i + j >= n)
                    break;

                if (Wartosci[i] == Wartosci[i + j])
                    dp[i][j] += dp[i + j][j];
            }
        }

        int mx = 0;
        FOR(i, n, 0)
        FOR(j, n + 1, 0)
        mx = max(mx, dp[i][j]);

        cout << mx << '\n';
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