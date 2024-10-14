#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5010;
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    vector<char> s3;

    for (int i = 1; i <= s1.size(); i++)
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] != s2[j - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }

    int i = s1.size(), j = s2.size();

    while (i > 0 && j > 0)
    {
        if (dp[i - 1][j - 1] + 1 == dp[i][j] && dp[i - 1][j] == dp[i][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1])
        {
            s3.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                --i;
            else
                --j;
        }
    }

    cout << dp[s1.size()][s2.size()] << "\n";

    for (int i = s3.size() - 1; i >= 0; i--)
        cout << s3[i];

    cout << "\n";
    return 0;
}