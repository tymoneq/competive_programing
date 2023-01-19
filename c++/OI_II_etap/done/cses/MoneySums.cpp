#include <bits/stdc++.h>

using namespace std;
int Coins[110];
bool dp[110][100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Coins[i];
        x += Coins[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= x; w++)
        {
            dp[i][w] = dp[i - 1][w];
            int prev_sum = w - Coins[i - 1];
            if (prev_sum >= 0 && dp[i - 1][prev_sum])
                dp[i][w] = 1;
        }

    vector<int> res;
    for (int i = 1; i <= x; i++)
        if (dp[n][i])
            res.push_back(i);
    cout << res.size() << "\n";
    for (int el : res)
        cout << el << " ";
    return 0;
}