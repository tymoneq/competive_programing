#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    vector<int> Prices(n);
    for (int &a : Prices)
        cin >> a;

    for (int operation = 1; operation <= k; operation++)
        for (int day = 1; day < n; day++)
        {
            int mx = dp[operation][day - 1];
            for (int m = 0; m < day; m++)
                mx = max(Prices[day] - Prices[m] + dp[operation - 1][m], mx);

            dp[operation][day] = mx;
        }

    cout << dp[k][n - 1] << "\n";
}