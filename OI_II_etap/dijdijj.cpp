#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 20;
ll D[N];
bool Vis[N];
struct edge
{
    int end, cost, indx;
};
vector<edge> adj[N];
pair<int, int> P[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b, c;
    ll res = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c, i});
        adj[b].push_back({a, c, i});
    }

    for (int i = 1; i <= n; i++)
        D[i] = numeric_limits<ll>::max();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    P[1] = {1, 0};
    D[1] = 0;
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        if (!Vis[v])
        {
            for (auto w : adj[v])
                if (D[w.end] > D[v] + w.cost)
                {
                    D[w.end] = D[v] + w.cost;
                    P[w.end] = {v, w.indx};
                    pq.push({D[w.end], w.end});
                }

            Vis[v] = 1;
        }
    }
    res += D[n];
    set<int> UsedEdges;
    int p;
    p = n;
    while (P[p].first != p)
    {
        UsedEdges.insert({P[p].second});
        p = P[p].first;
    }
    UsedEdges.insert(P[p].second);
    for (int i = 1; i <= n; i++)
    {
        D[i] = numeric_limits<ll>::max();
        Vis[i] = 0;
    }
    D[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        if (!Vis[v])
        {
            for (auto w : adj[v])
                if (D[w.end] > D[v] + w.cost && UsedEdges.find(w.indx) == UsedEdges.end())
                {
                    D[w.end] = D[v] + w.cost;
                    P[w.end] = {v, w.indx};
                    pq.push({D[w.end], w.end});
                }
            Vis[v] = 1;
        }
    }

    if (D[n] == numeric_limits<ll>::max())
        cout << -1 << "\n";
    else
        cout << D[n] + res << "\n";
    return 0;
}