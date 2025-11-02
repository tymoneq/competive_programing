#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;
typedef long long ll;
constexpr ll INF = 1e16;

vector<pair<int, int>> Graf[MAXN];
bool Vis[MAXN];
ll DistFromPedro[MAXN], DistFromG[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, P, G;
    cin >> N >> M >> P >> G;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Graf[a].push_back({b, c});
        Graf[b].push_back({a, c});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    for (int i = 0; i <= N; i++)
    {
        DistFromG[i] = DistFromPedro[i] = INF;
    }

    DistFromG[G] = 0;
    DistFromPedro[P] = 0;

    // najpierw dla G

    pq.push({0, G});

    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        if (!Vis[v])
            for (auto w : Graf[v])
            {
                if (DistFromG[w.first] > DistFromG[v] + w.second)
                {
                    DistFromG[w.first] = DistFromG[v] + w.second;
                    pq.push({DistFromG[w.first], w.first});
                }
            }

        Vis[v] = true;
    }

    for (int i = 0; i <= N; i++)
        Vis[i] = false;

    pq.push({0, P});

    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        if (!Vis[v])
            for (auto w : Graf[v])
            {
                if (w.first == G)
                    continue;
                if (DistFromPedro[w.first] > DistFromPedro[v] + w.second)
                {
                    DistFromPedro[w.first] = DistFromPedro[v] + w.second;
                    pq.push({DistFromPedro[w.first], w.first});
                }
            }

        Vis[v] = true;
    }

    set<int> Kandydaci;

    int dist = DistFromG[P];

    for (int i = 1; i <= N; i++)
    {
        if (i == P || i == G)
            continue;

        if (DistFromG[i] == dist)
            Kandydaci.insert(i);
    }

    set<int> Ans;
    for (int kand : Kandydaci)
    {
        if (DistFromPedro[kand] > 2 * dist)
            Ans.insert(kand);
    }

    if (Ans.size() == 0)
    {
        cout << "*" << "\n";
    }

    else
    {
        for (int a : Ans)
            cout << a << " ";
        cout << "\n";
    }

    return 0;
}