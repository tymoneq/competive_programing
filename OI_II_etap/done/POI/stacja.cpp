#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 1e6 + 10;

vector<int> adj[N];
int dp[N];
pair<ll, int> res;
ll total;

inline void dfs(int v, int p)
{
    dp[v] = 1;
    for (int w : adj[v])
        if (w != p)
        {
            dfs(w, v);
            dp[v] += dp[w];
        }
    total += dp[v];
}

inline void move_root(int old_root, int new_root)
{
    dp[old_root] -= dp[new_root];
    total -= dp[new_root];
    dp[new_root] += dp[old_root];
    total += dp[old_root];
}

inline void resDfs(int v, int p)
{

    res = max(res, {total, v});

    for (int w : adj[v])
        if (w != p)
        {
            move_root(v, w);
            resDfs(w, v);
            move_root(w, v);
        }
}

inline void solve(int v, int p)
{
    dfs(v, p);
    resDfs(v, p);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve(1, 1);

    cout << res.second << "\n";

    return 0;
}