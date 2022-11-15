#include <bits/stdc++.h>

using namespace std;
int collectGold(vector<vector<int>> &gold, int x, int y, int n, int m, vector<vector<int>> &dp)
{
    if ((x < 0) || (x == n) || (y == m))
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    int rightUpper = collectGold(gold, x - 1, y + 1, n, m, dp);
    int right = collectGold(gold, x, y + 1, n, m, dp);
    int rightlower = collectGold(gold, x + 1, y + 1, n, m, dp);
    return dp[x][y] = gold[x][y] + max(max(right, rightlower), rightUpper);
}
int getMaxGold(vector<vector<int>> &gold, int n, int m)
{
    int maxGold = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        int GoldCollected = collectGold(gold, i, 0, n, m, dp);
        maxGold = max(maxGold, GoldCollected);
    }
    return maxGold;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> goldmine(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            goldmine[i].push_back(a);
        }
    }
    cout << getMaxGold(goldmine, n, m);
    return 0;
}