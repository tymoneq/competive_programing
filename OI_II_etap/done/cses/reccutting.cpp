#include <bits/stdc++.h>

using namespace std;
int dp[510][510];
int INF = 1e7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 505; i++)
        for (int j = 1; j <= 505; j++)
            dp[i][j] = INF;
    for (int i = 1; i < 505; i++)
        dp[i][i] = 0;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
        {
            for (int cut = 1; cut < i; cut++)
                dp[i][j] = min(dp[i][j], dp[cut][j] + dp[i - cut][j] + 1);
            for (int cut = 1; cut < j; cut++)
                dp[i][j] = min(dp[i][j], dp[i][cut] + dp[i][j - cut] + 1);
        }
    cout << dp[a][b];
    return 0;
}