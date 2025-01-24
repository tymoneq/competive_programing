#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    struct Lca
    {
        int v, u, lca;
    };

    int N, M, Q;
    unsigned int MAXMask;
    vector<vector<int>> dp;
    vector<pair<int, int>> edges;
    vector<Lca> lca;

public:
    inline void read_data()
    {
        cin >> N >> M >> Q;

        dp.resize(N, vector<int>(1 << N, -1));
        edges.resize(M);

        MAXMask = 1 << N;

        FOR(i, M, 0)
        cin >> edges[i].first >> edges[i].second;

        lca.resize(Q);

        FOR(i, Q, 0)
        cin >> lca[i].u >> lca[i].v >> lca[i].lca;
    }

    inline void get_ans(int root, unsigned int mask)
    {
        if (dp[root][mask] != -1)
            return;

        dp[root][mask] = 0;

        if (__builtin_popcount(mask) == 1)
        {
            dp[root][mask] = 1;
            return;
        }

        if (__builtin_popcount(mask) == 2)
            FOR(i, M, 0)
            {
                int check_mask = 0;

                int u = 1 << (edges[i].first - 1);
                check_mask |= u;

                int v = 1 << (edges[i].second - 1);
                check_mask |= v;

                if (check_mask & mask == check_mask)
                {
                    dp[root][mask] = 1;
                    return;
                }
            }

        for (int submask = mask - 1; submask; submask = ((submask - 1) & submask))
        {
            int new_root = 0;

            for (int bit = 0; bit < N; bit++)
                if (submask & (1 << bit))
                {
                    new_root = bit;
                    break;
                }

            get_ans(new_root, submask);
            get_ans(root, submask ^ mask);

            dp[root][mask] += dp[new_root][submask] * dp[root][submask ^ mask];
        }
    }

    inline void solve()
    {
        read_data();

        get_ans(0, MAXMask - 1);

        cout << dp[0][MAXMask - 1] << '\n';
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