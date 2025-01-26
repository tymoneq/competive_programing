#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    static const ll INF = 1e18 + 5;
    int N, M;
    struct edge
    {
        int to, cost;
    };

    vector<vector<edge>> Miasto;
    vector<bool> Vis;
    vector<ll> Dist;
    ll best_res = INF;

    unsigned int best_ans;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

public:
    inline void read_data()
    {
        cin >> N >> M;

        Miasto.resize(N + 1);
        Vis.resize(N + 1);
        Dist.resize(N + 1);

        FOR(i, M, 0)
        {
            int from, to, cost;
            cin >> from >> to >> cost;

            Miasto[from].push_back({to, cost});
            Miasto[to].push_back({from, cost});
        }
    }

    inline void dijkstra(int city, int mask, ll &niezadowolenie)
    {

        FOR(i, N + 1, 1)
        {
            Vis[i] = false;
            Dist[i] = INF;
        }

        Dist[city + 1] = 0;

        pq.push({0, city + 1});

        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();

            if (Vis[v.second])
                continue;

            for (auto w : Miasto[v.second])
                if (Dist[w.to] > Dist[v.second] + w.cost)
                {
                    Dist[w.to] = Dist[v.second] + w.cost;
                    pq.push({Dist[w.to], w.to});
                }

            Vis[v.second] = true;
        }

        ll minDist = INF;

        FOR(i, N + 1, 1)
        {
            if (((mask >> (i - 1)) & 1) != (((mask >> city)) & 1))
                minDist = min(minDist, Dist[i]);
        }

        niezadowolenie = max(niezadowolenie, 0 ^ minDist);
    }

    inline void solve()
    {
        read_data();

        // 0 - > Bramka 1 -> Maska
        int total_number_of_mask = 1 << N;

        FOR(i, total_number_of_mask, 1)
        {
            ll niezadowolenie = 0;

            FOR(city, N, 0)
            dijkstra(city, i, niezadowolenie);

            if (niezadowolenie < best_res)
            {
                best_res = niezadowolenie;
                best_ans = i;
            }
        }

        // FOR(bit, N, 0)
        // {
        //     if ((best_ans >> bit) & 1)
        //         cout << "M";
        //     else
        //         cout << "B";
        // }

        // cout << "\n";

        cout << best_res << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve s;
    s.solve();

    return 0;
}