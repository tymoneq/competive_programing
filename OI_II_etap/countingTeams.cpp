#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unsigned long long res = 0;
        vector<vector<long long>> dp(rating.size() + 1, vector<long long>(3));
        // rosnoce
        for (int i = 0; i < rating.size(); i++)
        {
            dp[i][0] = 1;
            for (int k = 1; k < 3; k++)
                for (int j = i - 1; j >= 0; j--)
                    if (rating[j] < rating[i] && dp[j][k - 1] != 0)
                        dp[i][k] += dp[j][k] + 1;
        }
        for (int i = 0; i < rating.size(); i++)
            res += dp[i][2];

        for (int i = 0; i < rating.size(); i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = 0;

        for (int i = 0; i < rating.size(); i++)
        {
            dp[i][0] = 1;
            for (int k = 1; k < 3; k++)
                for (int j = i - 1; j >= 0; j--)
                    if (rating[j] > rating[i] && dp[j][k - 1] != 0)
                        dp[i][k] += dp[j][k] + 1;
        }
        for (int i = 0; i < rating.size(); i++)
            res += dp[i][2];
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> V = {2, 5, 3, 4, 1};
    cout << s.numTeams(V);
}