#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef unsigned long long ull;

class Solve
{
protected:
    int N, M;
    ull res = 0;
    vector<vector<int>> Grid;
    vector<ull> dp;

    struct id_w_gridzie
    {
        int val, idX, idY;
    };

public:
    inline void read_data()
    {
        cin >> N >> M;

        Grid.resize(N + 1, vector<int>(M + 1));

        FOR(i, N + 1, 1)
        FOR(j, M + 1, 1)
        cin >> Grid[i][j];
    }

    inline void N1_solve()
    {
        const int INF = 1e9 + 5;

        dp.resize(M + 1, 1);

        int mn = INF;
        int id;

        FOR(k, M, 0)
        {
            FOR(i, M + 1, 1)
            if (Grid[1][i] < mn)
            {
                mn = Grid[1][i];
                id = i;
            }

            if (id - 1 > 0 && Grid[1][id - 1] != INF)
                dp[id - 1] += dp[id];

            if (id + 1 <= N && Grid[1][id + 1] != INF)
                dp[id + 1] += dp[id];

            Grid[1][id] = INF;
        }

        FOR(i, M + 1, 1)
        res += dp[i];
    }

    inline void solve()
    {
        read_data();

        if (N == 1)
        {
            N1_solve();
        }
        else
        {

            FOR(i, N + 1, 1)
            FOR(j, M + 1, 1)
            {
                // sprawdzanie prostokatów

                vector<id_w_gridzie> wartosci;

                FOR(x, N + 1, i)
                FOR(y, M + 1, j)
                {
                    FOR(k, x + 1, i)
                    FOR(h, y + 1, j)
                    wartosci.push_back({Grid[k][h], k, h});

                    sort(wartosci.begin(), wartosci.end(), [this](id_w_gridzie &lhs, id_w_gridzie &rhs)
                         {
                             return lhs.val < rhs.val;
                         });
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

    Solve s;
    s.solve();
    return 0;
}