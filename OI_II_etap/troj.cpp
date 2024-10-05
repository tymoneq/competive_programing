#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1010;

vector<int> adj[N];
bool Vis[N][N];
int D[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, res = 0;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            D[i][j] = -1;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        q.push(i);
        Vis[i][i] = 1;
        D[i][i] = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int w : adj[v])
                if (!Vis[i][w])
                {
                    D[i][w] = D[i][v] + 1;
                    Vis[i][w] = 1;
                }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
            {
                if (D[i][j] == 1 && D[i][k] == 1 && D[j][k] == 1)
                    res++;
                else if (D[i][j] != 1 && D[i][k] != 1 && D[j][k] != 1)
                    res++;
            }
    cout << res << "\n";
    return 0;
}