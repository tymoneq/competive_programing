#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2510;
vector<int> adj[N];
bool Vis[N][N];
int d[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = numeric_limits<int>::max(), a, b;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<int, int>> Q;
    for (int i = 1; i <= n; i++)
    {
        Vis[i][i] = 1;
        d[i][i] = 0;
        Q.push({i, 0});
        while (!Q.empty())
        {
            auto v = Q.front();
            Q.pop();
            for (int w : adj[v.first])
            {
                if (!Vis[i][w])
                {
                    d[i][w] = d[i][v.first] + 1;
                    Vis[i][w] = 1;
                    Q.push({w, v.first});
                }
                else if (w != v.second && Vis[i][w])
                {
                    int current_res = d[i][w] + d[i][v.first] + 1;
                    ans = min(current_res, ans);
                }
            }
        }
    }
    if (ans == numeric_limits<int>::max())
        cout << -1 << "\n";
    else
        cout << ans << "\n";

    return 0;
}