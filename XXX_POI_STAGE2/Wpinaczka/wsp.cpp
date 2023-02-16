#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int M = 1e5+10;
vector<int> Graph[M];
int Foto[M];
ll res = 0;
bool Vis[M];
ll dp[M];
void dfs(int v)
{
    res += Foto[v];
    Vis[v] = 1;
    for (int w : Graph[v])
        if (!Vis[w])
            dfs(w);
}
void bfs(int v)
{
    queue<int> q;
    Vis[v] = 1;
    q.push(v);
    int w;
    while (!q.empty())
    {
        w = q.front();
        q.pop();
        for (int g : Graph[w])
            if (!Vis[g])
            {
                dp[g] += dp[w];
                Vis[g] = 1;
                q.push(g);
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, a, b;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> Foto[i];
        dp[i] = Foto[i];
    }
    if (n <= 1000)
    {

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            Graph[a].push_back(b);
        }

        for (int i = 1; i <= n; i++)
        {
            dfs(i);
            cout << res << "\n";
            res = 0;
            for (int j = 1; j <= n; j++)
                Vis[j] = 0;
        }
    }
    else
    {

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            Graph[b].push_back(a);
        }
        for (int i = n; i > 0; i--)
            if (!Vis[i])
                bfs(i);
        for (int i = 1; i <= n; i++)
            cout << dp[i] << "\n";
    }
    return 0;
}