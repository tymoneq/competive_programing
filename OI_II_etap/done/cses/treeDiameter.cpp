#include <bits/stdc++.h>
using namespace std;
constexpr int M = 10;
vector<int> Tree[M];
int dist, e;
inline void dfs(int v, int p, int depth)
{
    for (int u : Tree[v])
        if (u != p)
            dfs(u, v, depth + 1);

    if (depth > dist)
    {
        dist = depth;
        e = v;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--, b--;
        Tree[a].push_back(b), Tree[b].push_back(a);
    }
    dfs(0, 0, 0);

    dist = 0;
    dfs(e, -1, 0);
    cout << dist;
    return 0;
}