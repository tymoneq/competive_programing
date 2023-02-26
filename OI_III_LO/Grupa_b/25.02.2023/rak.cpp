#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e4 + 10, add = 1e4;
vector<int> Graph[M], Graph2[M];
bool vis[M];
int ConnectedComp[M], r, Res[M], Minus[M];
stack<int> S;
void dfs(int v)
{
    vis[v] = 1;
    for (int w : Graph[v])
        if (!vis[w])
            dfs(w);
    S.push(v);
}
void dfs2(int v)
{
    vis[v] = 1;
    ConnectedComp[v] = r;
    for (int w : Graph2[v])
        if (!vis[w])
            dfs2(w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, s;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> s;
        if (s == 1)
        {
            Graph[a].push_back(b + add);
            Graph[b + add].push_back(a);
            Graph[a + add].push_back(b);
            Graph2[a].push_back(b + add);
            Graph2[b + add].push_back(a);
            Graph2[b].push_back(a + add);
        }
        else
        {
            Graph[a].push_back(b);
            Graph[b + add].push_back(a + add);
            Graph2[b].push_back(a);
            Graph2[a + add].push_back(b + add);
        }
    }
    for (int i = add + 1; i <= add + n; i++)
        if (!vis[i])
            dfs(i);
    for (int i = 1; i < M; i++)
        vis[i] = 0;

    while (!S.empty())
    {
        if (!vis[S.top()])
        {
            r++;
            dfs2(S.top());
        }
        S.pop();
    }
    vector<set<int>> V(r + 1);
    for (int i = 1; i < M; i++)
        if (ConnectedComp[i] != 0)
        {
            if (i > add && V[ConnectedComp[i]].count(i - add))
                Minus[ConnectedComp[i]]++;
            V[ConnectedComp[i]].insert(i);
        }
    for (int i = 1; i <= r; i++)
    {
        auto it = V[i].upper_bound(add);
        while (it != V[i].end())
        {
            Res[*it - add] = V[i].size() - 1 - Minus[i];
            it++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << Res[i] << "\n";
    return 0;
}