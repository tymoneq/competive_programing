#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

constexpr ll INF = 1e16 + 10;
#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct NajszybszaDroga
{
    ll czas, ile_jeszcze_moge, v;
};

struct edge
{
    ll v, cost;
};

struct NajszybszaDrogaComparator
{
    bool operator()(const NajszybszaDroga &lhs, const NajszybszaDroga &rhs) const
    {
        if (lhs.czas == rhs.czas)
            return lhs.ile_jeszcze_moge > rhs.ile_jeszcze_moge;
        return lhs.czas < rhs.czas;
    }
};

class Solve
{
protected:
    ll n, m, Start, Koniec, IleMAXMoge, DlugoscPostoju;
    vector<ll> Dist;
    vector<bool> Vis;
    priority_queue<NajszybszaDroga, vector<NajszybszaDroga>, NajszybszaDrogaComparator> pq;
    vector<vector<edge>> Graf;

public:
    inline void read_data()
    {
        cin >> n >> m >> Start >> Koniec >> IleMAXMoge >> DlugoscPostoju;
        Graf.resize(n + 1);
        Dist.resize(n + 1, INF);
        Vis.resize(n + 1);

        FOR(i, m, 0)
        {
            ll from, to, cost;
            cin >> from >> to >> cost;
            if (cost > IleMAXMoge)
                continue;

            Graf[from].push_back({to, cost});
            Graf[to].push_back({from, cost});
        }
    }

    inline void dijkstra()
    {

        pq.push({0, IleMAXMoge, Start});
        Dist[Start] = 0;

        while (!pq.empty())
        {
            auto paulina = pq.top();
            pq.pop();
            // if (!Vis[paulina.v])
            {
                for (auto w : Graf[paulina.v])
                {
                    if (w.cost <= paulina.ile_jeszcze_moge && Dist[w.v] > paulina.czas + w.cost)
                    {
                        Dist[w.v] = paulina.czas + w.cost;
                        pq.push({Dist[w.v], paulina.ile_jeszcze_moge - w.cost, w.v});
                    }
                    else if (w.cost > paulina.ile_jeszcze_moge && (Dist[w.v] > paulina.czas + w.cost + DlugoscPostoju))
                    {
                        Dist[w.v] = paulina.czas + w.cost + DlugoscPostoju;
                        pq.push({Dist[w.v], IleMAXMoge - w.cost, w.v});
                    }
                }

                // Vis[paulina.v] = 1;
            }
        }
    }

    inline ll solve()
    {
        read_data();
        dijkstra();

        return Dist[Koniec];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve solution;

    ll ans = solution.solve();
    if (ans == INF)
        cout << "NIE";
    else
        cout << ans;
    cout << '\n';

    return 0;
}