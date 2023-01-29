#include <bits/stdc++.h>
using namespace std;
const int M = 2510;
const long long inf = 1e15 * -1;
struct edge
{
    int start_node, end_node, val;
};
vector<edge> Graph;
vector<int> G[M];
long long Dist[M];
long long Dist_2[M];
bool Visit[M];
bool Vist_from_1[M];
inline void dfs(int v)
{
    Visit[v] = 1;
    for (int w : G[v])
        if (!Visit[w])
            dfs(w);
}
inline void dfs_1(int v)
{
    Vist_from_1[v] = 1;
    for (int w : G[v])
        if (!Vist_from_1[w])
            dfs_1(w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        Dist[i] = inf;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        G[a].push_back(b);
        Graph.push_back({a, b, c});
    }
    Dist[1] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            Dist[Graph[j].end_node] = max(Dist[Graph[j].end_node], Dist[Graph[j].start_node] + Graph[j].val);
    for (int i = 1; i <= n; i++)
        Dist_2[i] = Dist[i];
    for (int j = 0; j < m; j++)
        if (Dist[Graph[j].end_node] < Dist[Graph[j].start_node] + Graph[j].val)
            Dist_2[Graph[j].end_node] = Dist[Graph[j].start_node] + Graph[j].val;

    vector<int> R;
    for (int i = 1; i <= n; i++)
        if (Dist[i] != Dist_2[i])
            R.push_back(i);
    dfs_1(1);
    for (int w : R)
        if (!Visit[w] && Vist_from_1[w])
            dfs(w);
    if (!Visit[n])
        cout << Dist[n];
    else
        cout << -1;
    return 0;
}