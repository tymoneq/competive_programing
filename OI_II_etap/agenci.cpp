#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 10, INF = 1e8;
bool Agent[N];
vector<int> adj[N];
int dp[N][3]; // 0-> dp w górę 1-> dp w dół

inline void calc(int v, int p)
{
    int suma = 0;

    for (int w : adj[v])
        if (w != p)
        {
            calc(w, v);
            suma += dp[w][2];
        }

    if (Agent[v])
    {
        dp[v][0] = suma;
        dp[v][1] = -INF;

        int mx = -INF;
        for (int w : adj[v])
            if (w != p)
                mx = max(mx, suma - dp[w][2] + 1 + dp[w][1]);

        dp[v][2] = max(suma, mx);
    }
    else
    {
        int mx = -INF;
        for (int w : adj[v])
            if (w != p)
                mx = max(mx, suma - dp[w][2] + 1 + dp[w][0]);

        dp[v][0] = mx;
        dp[v][2] = max(suma, mx);

        mx = -INF;
        for (int w : adj[v])
            if (w != p)
                mx = max(mx, suma - dp[w][2] + 1 + dp[w][1]);

        dp[v][1] = max(suma, mx);

        mx = -INF;
        for (int w : adj[v])
            for (int u : adj[v])
                if (w != p && w != u && u != p)
                    mx = max(mx, suma - dp[w][2] - dp[u][2] + 2 + dp[w][0] + dp[u][1]);

        dp[v][2] = max(dp[v][2], mx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        Agent[a] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calc(1, 1);

    cout << 2 * (n - k) - dp[1][2] << '\n';
    return 0;
}