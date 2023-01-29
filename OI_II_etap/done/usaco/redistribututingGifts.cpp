#include <bits/stdc++.h>

using namespace std;
const int M = 510;
vector<int> Graph[M], Revers[M];
bool Vis[M];
vector<int> path;
set<int> comp;

inline void dfs1(int v)
{
    Vis[v] = 1;
    for (int w : Graph[v])
        if (!Vis[w])
            dfs1(w);

    path.push_back(v);
}
inline void dfs2(int v)
{
    Vis[v] = 1;
    for (int w : Revers[v])
        if (!Vis[w])
            dfs2(w);
    comp.insert(v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        Graph[i].resize(n);
        for (int j = 0; j < n; j++)
            cin >> Graph[i][j];

        while (Graph[i].back() != i)
            Graph[i].pop_back();
        for (int j : Graph[i])
            Revers[j].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (!Vis[i])
            dfs1(i);
    for (int i = 0; i <= n; i++)
        Vis[i] = 0;

    reverse(path.begin(), path.end());
    vector<int> ans(n + 1);
    for (int i : path)
        if (!Vis[i])
        {
            dfs2(i);
            for (int j : comp)
                for (int k : Graph[j])
                    if (comp.count(k))
                    {
                        ans[j] = k;
                        break;
                    }
            comp.clear();
        }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
    return 0;
}