#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> dp;

inline void calc(int v, int p, int ekipyBudowlane)
{

    dp[v] = 0;
    int sum = 0;
    for (int w : adj[v])
        if (w != p)
        {
            calc(w, v, ekipyBudowlane);
            sum += dp[w] + 1;
        }

    dp[v] = max(sum - ekipyBudowlane, 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;

    adj.resize(n + 1);
    dp.resize(n + 1, 0);

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    int ans = 0, lo = 0, hi = n, mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        calc(1, 1, mid);

        if (dp[1] == 0)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    cout << ans << "\n";
    return 0;
}