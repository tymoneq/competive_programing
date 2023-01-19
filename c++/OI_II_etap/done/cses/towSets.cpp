#include <bits/stdc++.h>

using namespace std;
const int Mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int sum = (n + 1) * n / 2;
    if (sum % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    sum /= 2;
    vector<vector<int>> dp(n, vector<int>(sum + 1));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] += dp[i - 1][j];
            int prev = j - i;
            if (prev >= 0)
                dp[i][j] += dp[i - 1][prev];

            dp[i][j] %= Mod;
        }
    cout << dp[n - 1][sum];
    return 0;
}