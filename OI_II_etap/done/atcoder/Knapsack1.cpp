#include <bits/stdc++.h>

using namespace std;
const int M = 1e5+10;
long long  dp[110][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, W;
    cin >> n >> W;
    vector<pair<int, int>> Item(n);
    for (int i = 0; i < n; i++)
        cin >> Item[i].first >> Item[i].second;
    sort(Item.begin(), Item.end());

    for (int i = 1; i <= n; i++)
        for (int w = 1; w <= W; w++)
        {
            if (w - Item[i - 1].first >= 0)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - Item[i - 1].first] + Item[i - 1].second);
            else
                dp[i][w] = dp[i - 1][w];
        }

    cout << dp[n][W];
    return 0;
}