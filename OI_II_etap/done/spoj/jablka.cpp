#include <bits/stdc++.h>

using namespace std;

int dp[55][55];
int J[55][55];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> J[i][j];

    dp[0][0] = J[0][0];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + J[i][0];
    for (int i = 1; i < m; i++)
        dp[0][i] = dp[0][i - 1] + J[0][i];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + J[i][j];

    cout << dp[n - 1][m - 1];
    return 0;
}