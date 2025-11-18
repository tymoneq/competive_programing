#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e8, N = 210, K = 11;

int dp[N][N][K][N][K];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2, k1, k2;

    cin >> n1 >> n2 >> k1 >> k2;

    dp[1][1][1][0][0] = dp[1][0][0][1][1] = 1;

    for (int length = 1; length < n1 + n2; length++)
        for (int warrior = 0; warrior <= n1; warrior++)
            for (int warriorCnt = 0; warriorCnt <= k1; warriorCnt++)
                for (int horsemen = 0; horsemen <= n2; horsemen++)
                    for (int horsemanCnt = 0; horsemanCnt <= k2; horsemanCnt++)
                    {
                        if (warrior < warriorCnt || horsemen < horsemanCnt)
                            continue;

                        
                        dp[length][warrior][warriorCnt][horsemen][horsemanCnt] %= MOD;

                        int to_add = dp[length][warrior][warriorCnt][horsemen][horsemanCnt];
                        if (warriorCnt + 1 <= k1)
                            dp[length + 1][warrior + 1][warriorCnt + 1][horsemen][0] += to_add;

                        if (horsemanCnt + 1 <= k2)
                            dp[length + 1][warrior][0][horsemen + 1][horsemanCnt + 1] += to_add;

                        dp[length + 1][warrior + 1][1][horsemen][0] += to_add;
                        dp[length + 1][warrior][0][horsemen + 1][1] += to_add;
                    }

    int res = 0;
        for (int warriorCnt = 0; warriorCnt <= k1; warriorCnt++)
                for (int horsemanCnt = 0; horsemanCnt <= k2; horsemanCnt++)
                {
                    res += dp[n1 + n2][n1][warriorCnt][n2][horsemanCnt];
                    res %= MOD;
                }

    cout << res << "\n";

    return 0;
}
