#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int mod = 1e9 + 7;

ll dp[110][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll res;
    int n, k, d, suma;
    cin >> n >> k >> d;

    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j < 0)
                break;
            if (j < d)
            {
                dp[i][0] += dp[i - j][0];
                dp[i][1] += dp[i - j][1];
                dp[i][0] %= mod;
                dp[i][1] %= mod;
            }
            else
            {
                dp[i][1] += dp[i - j][0];
                dp[i][1] += dp[i - j][1];
                dp[i][1] %= mod;
            }
        }
    }

    cout << dp[n][1] << "\n";
    return 0;
}