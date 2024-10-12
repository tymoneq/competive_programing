#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 20;
ll D[N];
bool Vis[N];
struct edge
{
    int end, cost, indx;
};
vector<edge> adj[N];
pair<int, int> P[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b, c;
    ll res = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c, i});
        adj[b].push_back({a, c, i});
    }

    for (int i = 1; i <= n; i++)
        D[i] = numeric_limits<ll>::max();

    return 0;
}