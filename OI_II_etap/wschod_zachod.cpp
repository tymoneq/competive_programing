#include <bits/stdc++.h>

using namespace std;

#warning change N = 1e6+10;
constexpr int N = 20;
int d[N], depth[N];
bool Vis[N];
vector<int> adj[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w, z, a, b, p;
    cin >> n >> w >> z;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<pair<int, int>> pq;
    queue<pair<int, int>> q;
    cin >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> a;
        q.push({a, 0});
        depth[a] = 1;
    }
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        if (!Vis[v.first])
            for (int w : adj[v.first])
                if (w != v.second)
                {
                    depth[w] = max(depth[v.first] + 1, depth[w]);
                    q.push({w, v.first});
                }

        Vis[v.first] = 1;
    }
    int ans = numeric_limits<int>::max();
    for (int i = n; i >= n - z + 1; i--)
        ans = min(ans, d[i]);

    cout << ans << "\n";
    return 0;
}
