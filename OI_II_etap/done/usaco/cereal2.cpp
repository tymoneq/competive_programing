#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10, N = 1e5;
vector<int> Graph[M];
bool Vis[M];
vector<int> Res;
int r = 0;
inline void dfs(int v)
{
    Vis[v] = 1;
    int sons = 0;
    if (v <= N)
        Res.push_back(v);
    for (int w : Graph[v])
        if (!Vis[w])
        {
            sons++;
            dfs(w);
        }
    if (sons == 0 && v <= N)
        r++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        Graph[i].push_back(N + a);
        Graph[i].push_back(N + b);
        Graph[N + a].push_back(i);
        Graph[N + b].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (!Vis[i])
            dfs(i);
    cout << r << "\n";
    for (int el : Res)
        cout << el << "\n";
    return 0;
}