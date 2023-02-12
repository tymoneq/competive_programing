#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int M = 760, MOD = 1e9 + 7;
int Grid[M][M];
ll dp[M][M];

int main()
{
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R, C, k;
    cin >> R >> C >> k;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> Grid[i][j];
    dp[1][1] = 1;
   
    for (int i = 1; i < R; i++)
        for (int j = 1; j < C; j++)
            if (dp[i][j] != 0)
                for (int r = i + 1; r <= R; r++)
                    for (int c = j + 1; c <= C; c++)
                        if (Grid[i][j] != Grid[r][c])
                        {
                            dp[r][c] += dp[i][j];
                            dp[r][c] %= MOD;
                        }

    cout << dp[R][C];

    return 0;
}