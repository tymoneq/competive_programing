#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

constexpr ll INF = 1e16;
constexpr int N = 2e5 + 10;
vector<pair<int, ll>> Adj[N];
bool Vis[N];
vector<ll> Dist(N, INF);

struct mp
{
    ll sum, mx, mn, v;
    bool operator()(mp &lhs, mp &rhs) const
    {
        if (lhs.sum == rhs.sum)
        {
            ll dif_lhs = abs(lhs.mn - lhs.mx);
            ll dif_rhs = abs(rhs.mn - rhs.mx);

            return dif_lhs < dif_rhs;
        }
        return lhs.sum > rhs.sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Adj[a].push_back({b, c});
        Adj[b].push_back({a, c});
    }

    priority_queue<mp, vector<mp>, mp> pq;

    Dist[1] = 0;
    pq.push({0, 0, INF, 1});

    while (!pq.empty())
    {
        int v = pq.top().v;

        if (!Vis[v])
        {
            for (auto w : Adj[v])
                if (Dist[w.first] > pq.top().sum + w.second - max(pq.top().mx, w.second) + min(pq.top().mn, w.second))
                {
                    Dist[w.first] = pq.top().sum + w.second - max(pq.top().mx, w.second) + min(pq.top().mn, w.second);
                    pq.push({pq.top().sum + w.second, max(pq.top().mx, w.second), min(pq.top().mn, w.second), w.first});
                }

            Vis[v] = 1;
        }

        pq.pop();
    }

    for (int i = 2; i <= n; i++)
        cout << Dist[i] << " ";
    cout << "\n";
    return 0;
}