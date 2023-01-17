#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
vector<int> Graph1[M];
vector<int> Graph2[M];
stack<int> S;
bool Vis[M];
int Res[M];
int r = 1;
inline void dfs1(int v)
{
    Vis[v] = 1;
    for (int w : Graph1[v])
        if (!Vis[w])
            dfs1(w);
    S.push(v);
}
inline void dfs2(int v)
{
    Res[v] = r;
    Vis[v] = 1;
    for (int w : Graph2[v])
        if (!Vis[w])
            dfs2(w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph1[a].push_back(b);
        Graph2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!Vis[i])
            dfs1(i);
    for (int i = 1; i <= n; i++)
        Vis[i] = 0;
    dfs2(S.top());
    for (int i = 1; i <= n; i++)
        Vis[i] = 0;
    int g;
    while (!S.empty())
    {
        g = S.top();
        S.pop();
        if (!Vis[g])
        {
            dfs2(g);
            r++;
        }
    }
    for (int i = 1; i <= n; i++)
        Vis[i] = 0;
    for (int i = 1; i <= n; i++)
        if (Res[i] != 1)
        {
            cout << "NO\n"
                 << i << " ";
            dfs1(i);
            for (int j = 1; j <= n; j++)
                if (!Vis[j])
                {
                    cout << j;
                    break;
                }
            return 0;
        }
    cout << "YES";
    return 0;
}