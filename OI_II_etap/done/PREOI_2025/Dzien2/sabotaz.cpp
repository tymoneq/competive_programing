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

    vector<vector<int>> Planety;
    vector<ll> dp;

public:
    inline void read_data()
    {
        cin >> N >> M;

        Planety.resize(N + 1, vector<int>(M));
        dp.resize(N + 1);

        FOR(i, N + 1, 1)
        FOR(j, M, 0)
        cin >> Planety[i][j];
    }

    inline ll dist(int i, int j)
    {
        ll sum = 0;

        FOR(m, M, 0)
        sum += abs(Planety[i][m] - Planety[j][m]);

        return sum;
    }
    inline void solve()
    {
        read_data();

        dp[0] = dp[1] = 0;

        FOR(i, N + 1, 2)
        {
            dp[i] = dp[i - 1];
            FOR(j, i, 1)
            dp[i] = max(dp[i], dp[j - 1] + dist(i, j));
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