#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 2e5 + 10;
constexpr ll INF = 1e18;
ll Dist[M];
struct edge
{
    ll timel, airportr, timer;
};
vector<edge> Graph[M];
ll TIMES[M];
inline bool sortoo(edge &lhs, edge &rhs)
{
    if (lhs.timer == rhs.timer)
        lhs.timel < rhs.timel;
    return lhs.timer < rhs.timer;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll a, b, c, d;
    for (int i = 1; i <= n; i++)
        Dist[i] = INF;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c >> d;
        Graph[a].push_back({b, c, d});
    }
    for (int i = 1; i <= n; i++)
        sort(Graph[i].begin(), Graph[i].end(), sortoo);
    for (int i = 1; i <= n; i++)
        cin >> TIMES[i];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    Dist[1] = 0;
    pq.push({0, 1});
    bool firstone = 1;
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        for (auto w : Graph[v.second])
            if ((Dist[w.airportr] > w.timer) && ((w.timel >= Dist[v.second] + TIMES[v.second] || firstone)))
            {
                Dist[w.airportr] = w.timer;
                pq.push({Dist[w.airportr], w.airportr});
            }
        firstone = 0;
    }

    for (int i = 1; i <= n; i++)
        cout << (Dist[i] != INF ? Dist[i] : -1) << "\n";
    return 0;
}