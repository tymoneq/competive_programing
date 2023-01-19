#include <bits/stdc++.h>
using namespace std;
const int M = 110, N = 1e6 + 5, MOD = 1e9 + 7;
int Coins[M];
long long dp[N];
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
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= x; j++)
            if (j - Coins[i] >= 0)
            {
                dp[j] += dp[j - Coins[i]];
                dp[j] %= MOD;
            }

    cout << dp[x];
    return 0;
}