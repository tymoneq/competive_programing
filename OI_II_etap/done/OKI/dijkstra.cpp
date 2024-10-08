#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 10;
typedef long long ll;

ll D[N];
bool Vis[N];
vector<pair<int, int>> adj[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});

        adj[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
        D[i] = numeric_limits<ll>::max();

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    D[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        if (!Vis[v])
        {
            for (auto w : adj[v])
                if (D[w.first] > D[v] + w.second)
                {
                    D[w.first] = D[v] + w.second;
                    pq.push({D[w.first], w.first});
                }
            Vis[v] = 1;
        }
    }
    if (D[n] == numeric_limits<ll>::max())
        cout << -1 << "\n";
    else
        cout << D[n] << "\n";
    return 0;
}