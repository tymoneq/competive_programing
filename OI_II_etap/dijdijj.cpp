#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 1e5 + 10;
ll D[N];
bool Vis[N];
set<pair<int, int>> adj[N];
struct edge
{
    int a, b, c;
};

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
        adj[a].insert({b, c});
        adj[b].insert({a, c});
    }

    for (int i = 1; i <= n; i++)
        D[i] = numeric_limits<ll>::max();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    D[1] = 0;
    while (/* condition */)
    {
        /* code */
    }
    
    return 0;
}