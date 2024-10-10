#include <bits/stdc++.h>

using namespace std;

constexpr int N = 210, BASE = 1 << 15;
typedef long long ll;

struct edge
{
    int end, cost;
    int monsters = BASE;
};

struct wiedzmak
{
    ll time;
    int v;
    int Swords = BASE;
};

vector<edge> adj[N];
wiedzmak D[N];
int Kowal[N];

struct wiedzmakComparator
{

    bool operator()(wiedzmak &lhs, wiedzmak &rhs)
    {
        if (lhs.time == rhs.time)
            return lhs.Swords < rhs.Swords;
        return lhs.time > rhs.time;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, p, k, a, b, c, d, e;
    cin >> n >> m >> p >> k;
    for (int i = 1; i <= n; i++)
    {
        D[i].time = numeric_limits<ll>::max();
        Kowal[i] = BASE;
    }

    while (k--)
    {
        cin >> a >> b;
        while (b--)
        {
            cin >> c;
            int C = 1 << c;
            Kowal[a] |= C;
        }
    }
    while (m--)
    {
        cin >> a >> b >> c >> d;

        int A = BASE;
        while (d--)
        {
            cin >> e;
            int E = 1 << e;
            A |= E;
        }
        adj[a].push_back({b, c, A});
        adj[b].push_back({a, c, A});
    }

    priority_queue<wiedzmak, vector<wiedzmak>, wiedzmakComparator> pq;

    int A = BASE | Kowal[1];

    pq.push({0, 1, A});
    D[1].time = 0;
    D[1].Swords = A;
    ll res = numeric_limits<ll>::max();
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        if (v.v == n)
        {
            res = min(res, v.time);
            continue;
        }
        for (auto w : adj[v.v])
            if ((w.monsters & v.Swords) == w.monsters)
            {
                if (D[w.end].time > w.cost + v.time)
                {
                    D[w.end].time = w.cost + v.time;
                    D[w.end].Swords = v.Swords | Kowal[w.end];
                    if (w.end != n)
                        pq.push({D[w.end].time, w.end, (v.Swords | Kowal[w.end])});
                }
                else if ((v.Swords | D[w.end].Swords) != D[w.end].Swords)
                {

                    D[w.end].time = w.cost + v.time;
                    D[w.end].Swords = v.Swords | Kowal[w.end];
                    if (w.end != n)
                        pq.push({D[w.end].time, w.end, (v.Swords | Kowal[w.end])});
                }
                if (w.end == n)
                    res = min(res, D[w.end].time);
            }
    }
    if (res == numeric_limits<ll>::max())
        cout << -1 << "\n";
    else
        cout << res << "\n";
    return 0;
}