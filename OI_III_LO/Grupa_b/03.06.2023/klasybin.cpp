#include <bits/stdc++.h>

using namespace std;
constexpr int MAXLOG = 1 << 17;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, mx = 0;
    char z;
    cin >> n;

    vector<vector<int>> dp(n + 2, vector<int>(MAXLOG + 2));
    vector<bool> Points(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> z;
        if (z == '#')
            Points[i] = 1;
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = 2; j <= MAXLOG; j++)
        {
            if (i + prime[j] <= n)
            {
                if (Points[i])
                    dp[i][j] = dp[i + prime[j]][j] + 1;
                else
                    dp[i][j] = dp[i + prime[j]][j];
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