#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int Tower[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> Tower[i];
        vector<vector<int>> dp(2, vector<int>(n + 1, 1e9));
        dp[1][0] = 0;
        for (int i = 0; i < n; i++)
        {
            dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + Tower[i]);
            dp[1][i + 1] = min(dp[1][i + 1], dp[0][i]);
            if (i + 2 <= n)
            {
                dp[0][i + 2] = min(dp[0][i + 2], dp[1][i] + Tower[i] + Tower[i + 1]);
                dp[1][i + 2] = min(dp[1][i + 2], dp[0][i]);
            }
        }

        for (int i = 0; i < n; i++)
            Tower[i] = 0;
        cout << min(dp[0][n], dp[1][n]) << "\n";
    }
    return 0;
}