#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100, M = 100, INF = 1e9;
int Cows[N], Dist[N];
bool Vis[N];
vector<pair<int, int>> Graph[M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, a, b, c;
    cin >> n >> m >> t;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
        cin >> Cows[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        Graph[a].push_back({b, c});
        Graph[b].push_back({a, c});
        }
    for (int i = 2; i <= n; i++)
        Dist[i] = INF;
    int base = 0, mn, tmp;
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
        base += Dist[i] * Cows[i];
    mn = base;
    for (int i = 2; i <= n; i++)
    {
        tmp = 0;
        Graph[1].push_back({i, t});
        for (int j = 1; j <= n; j++)
        {
            Dist[j] = INF;
            Vis[j] = 0;
        }
        Dist[1] = 0;
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
        for (int j = 1; j <= n; j++)
            tmp += Dist[j] * Cows[j];
        mn = min(tmp, mn);
        Graph[1].pop_back();
    }
    cout << base - mn;
    return 0;
}