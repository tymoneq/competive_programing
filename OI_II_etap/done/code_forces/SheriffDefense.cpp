#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void calcdp(int v, int p, vector<vector<int>> &adj, vector<vector<ll>> &dp, vector<int> &Gold, const ll &c)
{
    // dfs
    ll sum = 0;
    for (int w : adj[v])
        if (w != p)
        {
            calcdp(w, v, adj, dp, Gold, c);
            sum += max(dp[w][1], dp[w][0]);
        }
    // calculating dp
    // state 0 -> nie biorę wierzchołka V
    // state 1 -> biorę wierzchołek V;
    dp[v][0] = sum;

    ll mx = Gold[v];

    for (int w : adj[v])
        if (w != p)
            mx = max({mx, mx + dp[w][0], mx + dp[w][1] - 2 * c});

    dp[v][1] = max((ll)0, mx);
}

inline void solve()
{
    int n;
    ll c;
    cin >> n >> c;

    vector<vector<int>> adj(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    vector<int> Gold(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> Gold[i];

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calcdp(1, 1, adj, dp, Gold, c);

    cout << max(dp[1][0], dp[1][1]) << "\n";
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