#include <bits/stdc++.h>

using namespace std;

int dp[5010][5010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < 5010; i++)
        for (int j = 0; j < 5010; j++)
            dp[i][j] = numeric_limits<int>::max();
    for (int i = 1; i < s1.size(); i++)
        dp[i][0] = i;
    for (int j = 1; j < s2.size(); j++)
        dp[0][j] = j;
    dp[0][0] = 0;
    for (int i = 1; i <= s1.size(); i++)
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }

    cout << dp[s1.size()][s2.size()];
    return 0;
}
