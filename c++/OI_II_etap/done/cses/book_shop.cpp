#include <bits/stdc++.h>
using namespace std;
constexpr int M = 1e3 + 10, X = 1e5 + 10;
pair<int, int> Books[M];
int dp[M][X];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> Books[i].first;
    for (int i = 0; i < n; i++)
        cin >> Books[i].second;
    sort(Books, Books + n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < X; j++)
        {
            if (Books[i - 1].first <= j)
                dp[i][j] = max(dp[i - 1][j - Books[i - 1].first] + Books[i - 1].second, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    cout << dp[n][x];
    return 0;
}