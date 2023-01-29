#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> visited(n + 1);
    vector<int> Distance(n + 1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int w = q.front();
        q.pop();
        for (int b : G[w])
        {
            if (!visited[b])
            {
                q.push(b);
                Distance[b] = 1 + Distance[w];
                visited[b] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            cout << Distance[i] << " ";
        }
        else
            cout << -1 << " ";
    }
    return 0;
}