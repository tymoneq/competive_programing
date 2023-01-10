#include <bits/stdc++.h>

using namespace std;
constexpr int M = 20;
int dp[M][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string word1, word2;
    cin >> word1 >> word2;

    for (int i = 1; i <= word1.size(); i++)
        for (int j = 1; j <= word2.size(); j++)
        {
            if (word1[i - 1] != word2[j - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }

    for (int i = 0; i <= word1.size(); i++)
    {
        for (int j = 0; j <= word2.size(); j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    return 0;
}