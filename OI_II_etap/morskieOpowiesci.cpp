#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5010;

vector<int> adj[N];
bool Vis[N];
int D[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, a, b, d;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            D[i][j] = numeric_limits<int>::max();
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        D[i][i] = 0;
        q.push(i);
        Vis[i] = 1;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int w : adj[v])
                if (!Vis[w])
                {
                    D[i][w] = D[i][v] + 1;
                    Vis[w] = 1;
                    q.push(w);
                }
        }

        for (int j = 1; j <= n; j++)
            Vis[j] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> d;
        if (D[a][b] > d)
            cout << "NIE\n";
        else
            cout << "TAK\n";
    }

    return 0;
}