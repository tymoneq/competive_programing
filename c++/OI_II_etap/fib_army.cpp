#include <bits/stdc++.h>

using namespace std;

int dp[21];
int main()
{
    int n;
    cin >> n;
    dp[1] = 1, dp[0] = 1;
    for (int i = 2; i <= 20; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n];
    return 0;
}