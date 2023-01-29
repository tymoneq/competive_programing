#include <bits/stdc++.h>

using namespace std;
int dp[61];
int main()
{
    int n;
    cin >> n;
    dp[2] = 2;
    for (int i = 3; i <= 60; i++)
        if (i % 2 == 0)
            dp[i] = dp[i - 2] * 2;

    cout << dp[n];
    return 0;
}