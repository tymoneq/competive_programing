#include <bits/stdc++.h>

using namespace std;

long long dp[1002][1002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, k, h;
    cin >> t;
    for (int i = 0; i <= 1001; i++)
        for (int j = 1; j <= 1001; j++)
        {
            if (j <= i)
                dp[i][j] = j;
            else
                dp[i][j] = (dp[i][j - 1] + dp[i][j - i - 1] + 1) % 1000000009;
        }
    for (int i = 0; i < t; i++)
    {
        cin >> k >> h;
        cout << dp[k][h] <<"\n";
    }

    return 0;
}