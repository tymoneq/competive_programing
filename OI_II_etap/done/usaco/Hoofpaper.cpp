#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e5 + 10;
int dp[M][22][3];
int Moves[M];
#define HOOF 0
#define PAPER 1
#define SCISSOR 2
int addone(int a, int b)
{
    if (a == HOOF && Moves[b] == SCISSOR)
        return 1;
    if (a == SCISSOR && Moves[b] == PAPER)
        return 1;
    if (a == PAPER && Moves[b] == HOOF)
        return 1;
    return 0;
}
int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    char z;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> z;
        if (z == 'H')
            Moves[i] = HOOF;
        else if (z == 'S')
            Moves[i] = SCISSOR;
        else if (z == 'P')
            Moves[i] = PAPER;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < k + 2; j++)
        {
            int add = addone(HOOF, i);
            dp[i][j][HOOF] = max(dp[i - 1][j][HOOF] + add, max(dp[i - 1][j - 1][PAPER] + add, dp[i - 1][j - 1][SCISSOR] + add));

            add = addone(SCISSOR, i);
            dp[i][j][SCISSOR] = max(dp[i - 1][j][SCISSOR] + add, max(dp[i - 1][j - 1][PAPER] + add, dp[i - 1][j - 1][HOOF] + add));

            add = addone(PAPER, i);
            dp[i][j][PAPER] = max(dp[i - 1][j][PAPER] + add, max(dp[i - 1][j - 1][HOOF] + add, dp[i - 1][j - 1][SCISSOR] + add));
            if (n == i)
                ans = max(dp[i][j][HOOF], max(dp[i][j][SCISSOR], dp[i][j][PAPER]));
        }

    cout << ans;
    return 0;
}
