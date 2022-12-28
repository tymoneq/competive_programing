#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> Graph[550];
long long Dist[550][550];
bool Vis[550];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, a, b, c, v, w;
    long long weight;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        Graph[a].push_back(make_pair(b, c));
        Graph[b].push_back(make_pair(a, c));
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            Dist[i][j] = numeric_limits<long long>::max();
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i = 1; i <= n; i++)
    {
        pq.push(make_pair(0, i));
        Dist[i][i] = 0;
        while (!pq.empty())
        {
            v = pq.top().second;
            pq.pop();
            if (!Vis[v])
                for (auto j = Graph[v].begin(); j != Graph[v].end(); j++)
                {
                    w = (*j).first;
                    weight = (*j).second;
                    if (Dist[i][w] > Dist[i][v] + weight)
                    {
                        Dist[i][w] = Dist[i][v] + weight;
                        pq.push(make_pair(Dist[i][w], w));
                    }
                }

            Vis[v] = 1;
        }
        for (int j = 1; j <= n; j++)
            Vis[j] = 0;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        if (Dist[a][b] == numeric_limits<long long>::max())
            Dist[a][b] = -1;
        cout << Dist[a][b] << "\n";
    }
    return 0;
}