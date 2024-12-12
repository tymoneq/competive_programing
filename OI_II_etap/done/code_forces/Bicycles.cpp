#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace std;
typedef long long ll;

const ll INF = 1e15;

inline void solve()
{

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1));
    vector<vector<pair<ll, ll>>> Adj(n + 1);
    vector<vector<ll>> Dist(n + 1, vector<ll>(n + 1));
    vector<ll> Cost(n + 1);
    vector<bool> Vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = INF;

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(c, adj[a][b]);
        adj[b][a] = min(c, adj[b][a]);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> Cost[i];
        Vis[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            Dist[i][j] = INF;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == INF || i == j)
                continue;

            Adj[i].push_back({j, adj[i][j]});
            Adj[j].push_back({i, adj[j][i]});
        }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    for (int i = 1; i <= n; i++)
    {
        Dist[i][i] = 0;
        pq.push({0, i});
        while (!pq.empty())
        {
            int v = pq.top().second;
            pq.pop();
            if (!Vis[v])
            {
                for (auto w : Adj[v])
                    if (Dist[i][w.first] > Dist[i][v] + w.second)
                    {
                        Dist[i][w.first] = Dist[i][v] + w.second;
                        pq.push({Dist[i][w.first], w.first});
                    }
                Vis[v] = 1;
            }
        }

        for (int j = 1; j <= n; j++)
            Dist[i][j] *= Cost[i];

        for (int j = 1; j <= n; j++)
            Vis[j] = 0;
    }
    vector<ll> Res(n + 1, INF);
    Res[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int v = pq.top().second;
        ll t = pq.top().first;
        pq.pop();

        if (!Vis[v])
        {
            for (int i = 1; i <= n; i++)
            {
                if (i == v || Dist[v][i] == 0)
                    continue;

                if (Res[i] > Dist[v][i] + t)
                {
                    Res[i] = Dist[v][i] + t;
                    pq.push({Res[i], i});
                }
            }
            Vis[v] = 1;
        }
    }

    cout << Res[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}