#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, M;
    vector<int> Ans;

    vector<vector<int>> ReverseGraph;
    vector<vector<int>> Graph;

    vector<bool> Vis;

public:
    inline void
    read_data()
    {
        cin >> N >> M;

        Ans.resize(N + 1, 1);
        ReverseGraph.resize(N + 1);
        Graph.resize(N + 1);
        Vis.resize(N + 1);

        FOR(i, M, 0)
        {
            int from, to;
            cin >> from >> to;

            Graph[from].push_back(to);
            ReverseGraph[to].push_back(from);
        }
    }

    inline void dfs_1(int v)
    {
        Vis[v] = true;

        for (int w : Graph[v])
            if (!Vis[w])
                dfs_1(w);
    }

    inline void dfs_2(int v)
    {
        Vis[v] = true;

        for (int w : ReverseGraph[v])
            if (!Vis[w])
                dfs_2(w);
    }

    inline void solve()
    {
        read_data();

        FOR(i, N + 1, 1)
        {
            FOR(j, N + 1, 1)
            Vis[j] = false;

            dfs_1(i);
            dfs_2(i);

            int cnt = 0;
            FOR(j, N + 1, 1)
            if (Vis[j])
                cnt++;

            if (cnt == N)
                Ans[i] = 1;

            else
                Ans[i] = -1;
        }

        FOR(i, N + 1, 1)
        cout << Ans[i] << " ";

        cout << '\n';
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