#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
vector<pair<int, int>> Graph[M];
long long d[M];
bool Vis[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, c, u, v;
    long long weight;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        d[i] = numeric_limits<long long>::max();
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        Graph[a].push_back(make_pair(b, c));
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0, 1));
    d[1] = 0;
    while (!pq.empty())
    {
        u = pq.top().second;
        pq.pop();
        if (!Vis[u])
            for (auto i = Graph[u].begin(); i != Graph[u].end(); i++)
            {
                v = (*i).first;
                weight = (*i).second;
                if (d[v] > d[u] + weight)
                {
                    d[v] = d[u] + weight;
                    pq.push(make_pair(d[v], v));
                }
            }
        Vis[u] = 1;
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    return 0;
}