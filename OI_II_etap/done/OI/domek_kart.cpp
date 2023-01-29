#include <bits/stdc++.h>
using namespace std;
const int base = 1 << 17, K = 22;
long long dp[base][K];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, a, b = 0, sum = 0, tmp;
    cin >> n >> k;
    vector<int> Leves;
    int g = 2;
    Leves.push_back(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < g; j++)
        {
            cin >> a;
            b++;
            sum += a;
            if (b % 2 == 0)
            {
                Leves.push_back(sum);
                b = 0;
                sum = 0;
            }
        }
        g *= 2;
    }
    k /= 2;
    for (int i = g / 4; i < g / 2; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = Leves[i];
    for (int i = pow(2, n - 1) - 1; i > 0; i--)
    {
        dp[i][1] = Leves[i];
        for (int j = 2; j <= k; j++)
            for (int h = 0; h < j; h++)
                dp[i][j] = max(dp[i][j], dp[i * 2][h] + dp[i * 2 + 1][j - h - 1] + Leves[i]);
    }

    cout << dp[1][k];
    return 0;
}