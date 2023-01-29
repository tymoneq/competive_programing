#include <bits/stdc++.h>

using namespace std;
const int M = 110, N = 1e6 + 5, MOD = 1e9 + 7;
long long dp[N];
int Coins[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> Coins[i];
        dp[Coins[i]] = 1;
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
            if (i - Coins[j] > 0)
                dp[i] += dp[i - Coins[j]];
        dp[i] %= MOD;
    }
    cout << dp[x];
    return 0;
}