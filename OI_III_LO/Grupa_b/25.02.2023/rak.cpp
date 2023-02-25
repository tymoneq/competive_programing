#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e4 + 10, add = 1e4;
vector<int> Graph[M], Graph2[M];
bool vis[M], vis2[M];
int Res[M], r;
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
    vis2[v] = 1;
    if (vis[v])
        Res[v] = r;
    for (int w : Graph2[v])
        if (!vis2[w])
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
    int res = 0;
    for (int i = add + 1; i <= add + n; i++)
    {
        res = 0, r = 1;
        dfs(i);
        while (!S.empty())
        {
            if (!vis2[S.top()])
            {
                dfs2(S.top());
                r++;
            }
            S.pop();
        }
        for (int j = 1; j < M; j++)
        {
            if (Res[j] == 1)
                res++;
            Res[j] = 0;
            vis[j] = 0;
            vis2[j] = 0;
        }
        cout << res - 1 << "\n";
    }

    return 0;
}