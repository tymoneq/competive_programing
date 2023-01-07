#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
int dp[M], Num[105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> Num[i];

    for (int i = 0; i <= x; i++)
        dp[i] = 10000000;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int w = 0; w <= x; w++)
            if (w - Num[i] >= 0)
                dp[w] = min(dp[w], dp[w - Num[i]] + 1);
    cout << (dp[x] == 10000000 ? -1 : dp[x]);
    return 0;
}