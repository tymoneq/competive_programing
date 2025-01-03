#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    struct edge
    {
        int to, cost;
    };

    struct pqElement
    {
        ll cost;
        vector<int> Path;
    };

    struct pqElementComparator
    {
        const bool operator()(const pqElement &lhs, const pqElement &rhs)
        {

            if (lhs.cost == rhs.cost)
            {
                for (int i = min(lhs.Path.size(), rhs.Path.size()) - 1; i >= 0; i--)
                {
                    if (lhs.Path[i] > rhs.Path[i])
                        return true;
                    else if (lhs.Path[i] < rhs.Path[i])
                        return false;
                }

                return lhs.Path.size() > rhs.Path.size();
            }
            return lhs.cost > rhs.cost;
        }
    };

    vector<vector<edge>> Graf;
    vector<ll> Dist, Cows, Path, IleKrow;
    vector<bool> vis;
    priority_queue<pqElement, vector<pqElement>, pqElementComparator> pq;
    ll N, M, T, maxReduction = 0;
    const ll INF = 1e18 + 5;

public:
    inline void read_data()
    {
        cin >> N >> M >> T;

        Graf.resize(N + 1);
        Dist.resize(N + 1, INF);
        Cows.resize(N + 1);
        Path.resize(N + 1);
        IleKrow.resize(N + 1);
        vis.resize(N + 1);

        FOR(i, N + 1, 1)
        cin >> Cows[i];

        FOR(i, M, 0)
        {
            int a, b, c;
            cin >> a >> b >> c;
            Graf[a].push_back({b, c});
            Graf[b].push_back({a, c});
        }
    }

    inline void dijkstra()
    {
        Dist[1] = 0;
        Path[1] = 0;
        pq.push({0, {1}});

        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();
            int lastV = v.Path[v.Path.size() - 1];

            if (!vis[lastV])
            {
                for (auto w : Graf[lastV])
                {
                    if (Dist[w.to] > v.cost + w.cost)
                    {
                        Dist[w.to] = v.cost + w.cost;
                        Path[w.to] = lastV;
                        vector<int> path = v.Path;
                        path.push_back(w.to);
                        pq.push({Dist[w.to], path});
                    }
                    if (Dist[w.to] >= v.cost + w.cost && Path[w.to] > lastV)
                    {
                        Dist[w.to] = v.cost + w.cost;
                        Path[w.to] = lastV;
                        vector<int> path = v.Path;
                        path.push_back(w.to);
                        pq.push({Dist[w.to], path});
                    }
                }

                vis[lastV];
            }
        }
    }
    inline void preperingGraph()
    {

        FOR(i, N + 1, 1)
        {
            int v = i;
            while (v != 0)
            {
                IleKrow[v] += Cows[i];
                v = Path[v];
            }
        }
    }
    inline void calculatingScore()
    {
        FOR(i, N + 1, 2)
        maxReduction = max(maxReduction, (Dist[i] - T) * IleKrow[i]);
    }
    inline void solve()
    {
        read_data();
        dijkstra();
        preperingGraph();
        calculatingScore();

        cout << maxReduction << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);

    Solve solution;
    solution.solve();
    return 0;
}