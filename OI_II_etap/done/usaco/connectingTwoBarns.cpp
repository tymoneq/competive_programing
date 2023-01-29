#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int M = 1e5 + 10;
vector<int> Graph[M];
vector<int> Comps[M];
int Comp[M];
inline void dfs(int v, int c)
{
    Comp[v] = c;
    for (int w : Graph[v])
        if (Comp[w] == -1)
            dfs(w, c);
}
ll cost(int a, int b)
{
    int dist = M;
    for (int u : Comps[a])
    {
        int i = lower_bound(Comps[b].begin(), Comps[b].end(), u) - Comps[b].begin();
        if (i > 0)
            dist = min(dist, abs(Comps[b][i - 1] - u));
        if (i < Comps[b].size())
            dist = min(dist, abs(Comps[b][i] - u));
    }
    return (ll)dist * dist;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, a, b, cur = -1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        cur = -1;
        for (int j = 0; j < n; j++)
        {
            Graph[j].clear();
            Comps[j].clear();
            Comp[j] = -1;
        }
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b;
            a--, b--;
            Graph[a].push_back(b);
            Graph[b++].push_back(a++);
        }
        for (int j = 0; j < n; j++)
            if (Comp[j] == -1)
                dfs(j, ++cur);

        for (int j = 0; j < n; j++)
            Comps[Comp[j]].push_back(j);
        ll res = cost(Comp[0], Comp[n - 1]);
        for (int c = 1; c < cur; c++)
            res = min(res, cost(c, Comp[0]) + cost(c, Comp[n - 1]));
        cout << res << "\n";
    }
    return 0;
}