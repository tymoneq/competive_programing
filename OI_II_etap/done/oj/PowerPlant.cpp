#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;

vector<int> adj[N];
int hasPowerPlant[N];
int dp[N];
int ans;
inline void calc(int v, int p)
{
    for (int w : adj[v])
        if (w != p)
            calc(w, v);

    int sum = 0, mx = 0;
    for (int w : adj[v])
        if (w != p)
        {
            sum += dp[w];
            mx = max(dp[w], mx);
        }

    dp[v] = max(hasPowerPlant[v], sum - hasPowerPlant[v]);
    ans = max({ans, sum - hasPowerPlant[v], mx + hasPowerPlant[v]});
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

    for (int i = 1; i <= n; i++)
    {
        char a;
        cin >> a;
        if (a - '0' == 1)
            hasPowerPlant[i] = 1;
    }

    calc(1, 1);

    cout << ans << "\n";

    return 0;
}