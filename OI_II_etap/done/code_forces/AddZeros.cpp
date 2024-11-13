#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll resMAX;

inline void dfs(ll v, map<ll, bool> &vis, map<ll, vector<ll>> &adj)
{
    resMAX = max(resMAX, v);
    for (ll w : adj[v])
        if (!vis[w])
        {
            vis[w] = 1;
            dfs(w, vis, adj);
        }
}

inline void solve()
{
    int n;
    map<ll, vector<ll>> adj;
    map<ll, bool> vis;
    cin >> n;

    resMAX = 0;
    vector<ll> A(n);

    for (ll &a : A)
        cin >> a;

    // creating graph
    for (int i = 1; i < n; i++)
    {
        ll edge = A[i] + i;
        adj[edge].push_back(edge + i);
        vis[edge] = 0;
    }

    dfs(n, vis, adj);

    cout << resMAX << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}