#include <bits/stdc++.h>

using namespace std;
bool visited[20];
int spoj[20];
void dfs(int a, vector<vector<int>> &G, int i)
{
    visited[a] = true;
    spoj[a] = i;
    for (int b : G[a])
    {
        if (!visited[b])
            dfs(b, G, i);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, G, i + 1);
        }
    }
    for (auto el : spoj)
    {
        cout << el << " ";
    }
    return 0;
}
