#include <bits/stdc++.h>

using namespace std;
const int M = 1e4 + 10, INF = 1e8;
vector<pair<int, int>> Graph[M];
int Cows[M];
bool Vis[M];
int Dist[M];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    int n, m, t, a, b, c;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        cin >> Cows[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        Graph[a].push_back({b, c});
        Graph[b].push_back({a, c});
    }
    int d = 0;
    for (int i = 2; i <= n; i++)
        Dist[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        if (!Vis[v.second])
            for (auto w : Graph[v.second])
                if (Dist[w.first] > w.second + Dist[v.second])
                {
                    Dist[w.first] = w.second + Dist[v.second];
                    pq.push({Dist[w.first], w.first});
                }

        Vis[v.second] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        d += Dist[i] * Cows[i];
        Dist[i] = INF;
        Vis[i] = 0;
    }
    int res = numeric_limits<int>::max();
    for (int i = 2; i <= n; i++)
    {
        Graph[1].push_back({i, t});
        Graph[i].push_back({1, t});
        pq.push({0, 1});
        Dist[1] = 0;
        int D = 0;
        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();
            if (!Vis[v.second])
                for (auto w : Graph[v.second])
                    if (Dist[w.first] > w.second + Dist[v.second])
                    {
                        Dist[w.first] = w.second + Dist[v.second];
                        pq.push({Dist[w.first], w.first});
                    }

            Vis[v.second] = 1;
        }
        for (int j = 1; j <= n; j++)
        {
            D += Dist[j] * Cows[j];
            Dist[j] = INF;
            Vis[j] = 0;
        }
        if (d > D)
            res = min(res, d - D);

        Graph[1].pop_back();
        Graph[i].pop_back();
    }

    cout << res;
    fin.close(), fout.close();
    return 0;
}