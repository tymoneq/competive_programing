#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10, MOD = 1e9 + 7;
int V[M];
long long dp[M][110];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> V[i];
    if (V[0] == 0)
        fill(dp[0], dp[0] + 101, 1);
    else
        dp[0][V[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (V[i] == 0)
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i - 1][j];
                if (j - 1 > 0)
                    dp[i][j] += dp[i - 1][j - 1];
                if (j + 1 <= m)
                    dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        else
        {
            dp[i][V[i]] += dp[i - 1][V[i]];
            if (V[i] - 1 > 0)
                dp[i][V[i]] += dp[i - 1][V[i] - 1];
            if (V[i] + 1 <= m)
                dp[i][V[i]] += dp[i - 1][V[i] + 1];
            dp[i][V[i]] %= MOD;
        }
    }
    long long res = 0;
    for (int i = 1; i <= m; i++)
        res += dp[n - 1][i], res %= MOD;

    cout << res;
    return 0;
}
