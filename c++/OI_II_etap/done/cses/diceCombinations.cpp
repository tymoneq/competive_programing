#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e6 + 10;
const int mod = 1e9 + 7;
long long dp[M];
int main()
{
    int n, j = 1;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] * 2;
        if (i >= 7 && i < 9)
            dp[i] -= 1;
        if (i >= 9)
        {
            dp[i] -= 2 * j;
            j++;
        }
        dp[i] %= mod;
    }
 
    cout << dp[n];
}