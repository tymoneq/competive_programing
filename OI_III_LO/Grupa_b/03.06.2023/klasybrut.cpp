#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, mx = 0;
    char z;
    cin >> n;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    vector<bool> Points(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> z;
        if (z == '#')
            Points[i] = 1;
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = 2; j <= n; j++)
        {
            if (i + j <= n)
            {
                if (Points[i])
                    dp[i][j] = dp[i + j][j] + 1;
                else
                    dp[i][j] = dp[i + j][j];
            }
            else
            {
                if (Points[i])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx;
    return 0;
}