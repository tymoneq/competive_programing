#include <bits/stdc++.h>
// działa na 40%
using namespace std;
typedef long long ll;
const ll INF = 1e15;
const int M = 1e5 + 10;
vector<pair<int, int>> Graph[M];
bool Vis[M];
ll Dist[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, n, m, a, b, weight;
    pair<int, int> v;
    cin >> t;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int k = 0; k < t; k++)
    {
        cin >> n >> m;
        for (int i = 1; i <= n + 1; i++)
        {
            Dist[i] = INF;
            Graph[i].clear();
            Vis[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            Graph[a].push_back({b, 0});
            Graph[b].push_back({a, 0});
        }
        for (int i = 1; i <= n; i++)
        {

            Graph[i].push_back({i + 1, 1});
            Graph[i + 1].push_back({i, 1});
        }
        Dist[1] = 0;
        pq.push({0, 1});
        while (!pq.empty())
        {
            v = pq.top();
            pq.pop();
            for (auto w : Graph[v.second])
                if (!Vis[w.first])
                {
                    weight = Dist[v.second] + w.second;
                    if (Dist[w.first] > weight)
                    {
                        Dist[w.first] = weight;
                        pq.push({weight, w.first});
                    }
                }

            Vis[v.second] = 1;
        }
        cout << Dist[n] << "\n";
    }
    return 0;
}