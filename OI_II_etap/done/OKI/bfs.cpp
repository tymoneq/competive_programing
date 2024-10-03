#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int N = 1e6 + 10;

bool Vis[N];
int d[N];
vector<int> adj[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    Vis[0] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w : adj[v])
            if (!Vis[w])
            {
                d[w] = d[v] + 1;
                Vis[w] = 1;
                q.push(w);
            }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += d[i];
    cout << ans*2 << "\n";
    return 0;
}