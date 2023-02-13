#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7, M = 1e6 + 10;
long long dp[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    dp[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '0')
            dp[i] = dp[i - 1];
        else if (s[i - 1] == '1' && (s[i] > '2' || i == s.size() - 1 || (i < s.size() - 1 && s[i + 1] != '0')))
        {
            if (dp[i - 1] == 1)
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        else if (s[i - 1] == '2' && s[i] <= '6' && (s[i] > '2' || i == s.size() - 1 || (i < s.size() - 1 && s[i + 1] != '0')))
            if (dp[i - 1] == 1)
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1];
        dp[i] %= MOD;
    }
    cout << dp[s.size() - 1];
    return 0;
}