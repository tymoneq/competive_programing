#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
vector<int> Graph[M];
vector<int> Graph_2[M];
bool Visited[M];
int Res[M];
stack<int> S;
int r = 1;
inline void dfs_1(int v)
{
    Visited[v] = 1;
    for (int w : Graph[v])
        if (!Visited[w])
            dfs_1(w);
    S.push(v);
}
inline void dfs_2(int v)
{
    Res[v] = r;
    Visited[v] = 1;
    for (int w : Graph_2[v])
        if (!Visited[w])
            dfs_2(w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, g;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph_2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!Visited[i])
            dfs_1(i);
    for (int i = 1; i <= n; i++)
        Visited[i] = 0;
    while (!S.empty())
    {
        g = S.top();
        S.pop();
        if (!Visited[g])
        {
            dfs_2(g);
            r++;
        }
    }
    cout << r - 1 << "\n";
    for (int i = 1; i <= n; i++)
        cout << Res[i] << " ";
    return 0;
}