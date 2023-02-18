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
    dp[1][1] = 0;
    for (int i = 1; i <= a; i++)
        dp[1][i] = i;
    for (int i = 1; i <= b; i++)
        dp[i][1] = i;
    for (int i = 2; i <= a; i++)
        for (int j = 2; j <= b; j++)
        {
            if (j == i)
                dp[i][j] == 0;
            else
            {
                for (int k = 1; k < a; k++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[a - k][j]);
                for (int k = 1; k < b; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][b - k]);
            }
        }
    cout << dp[a][b];
    return 0;
}