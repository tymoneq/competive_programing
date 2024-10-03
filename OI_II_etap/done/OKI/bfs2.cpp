#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 10;

vector<int> adj[N];
bool Vis[N];
int d[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        d[i] = -1;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    d[1] = 0;
    Vis[1] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w : adj[v])
            if (!Vis[w])
            {
                Vis[w] = 1;
                d[w] = d[v] + 1;
                q.push(w);
            }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";

    cout << "\n";

    return 0;
}
