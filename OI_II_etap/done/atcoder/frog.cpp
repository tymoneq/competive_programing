#include <bits/stdc++.h>

using namespace std;
const int M = 1e5 + 10;
long long dp[M];
int H[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> H[i];
    dp[0] = 0;
    dp[1] = abs(H[0] - H[1]);
    for (int i = 2; i < n; i++)
        dp[i] = min(dp[i - 1] + abs(H[i] - H[i - 1]), dp[i - 2] + abs(H[i] - H[i - 2]));

    cout << dp[n-1];
}