#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[210][210][3]; // first last int, second zero count

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> A(n);
    for (ll &a : A)
        cin >> a;

    for (int i = 1; i <= n; i++)
    {
        int zero_count = 0;
        int pow2 = 0, pow5 = 0;

        ll a = A[i - 1];
        while (a % 10 == 0 && a != 0)
        {
            zero_count++;
            a /= 10;
        }

        while (a > 0 && a % 2 == 0)
        {
            pow2++;
            a /= 2;
        }
        while (a > 0 && a % 5 == 0)
        {
            pow5++;
            a /= 5;
        }

        for (int K = 1; K <= min(k, i); K++)
            for (int j = 1; j <= i; j++)
            {
                if (K == 1 || i == 1)
                {
                    dp[i][K][0] = zero_count;
                    dp[i][K][1] = pow2;
                    dp[i][K][2] = pow5;
                    break;
                }
                if (j == i)
                    break;
                // zrób działania na typie 128 bitowym
                if (zero_count + min(dp[j][K - 1][1] + pow2, dp[j][K - 1][2] + pow5) + dp[j][K - 1][0] > dp[j][K][0] && zero_count + min(dp[j][K - 1][1] + pow2, dp[j][K - 1][2] + pow5) + dp[j][K - 1][0] > dp[i][K][0])
                {
                    dp[i][K][0] = zero_count + min(dp[j][K - 1][1] + pow2, dp[j][K - 1][2] + pow5) + dp[j][K - 1][0];
                    dp[i][K][1] = dp[j][K - 1][1] + pow2;
                    dp[i][K][2] = dp[j][K - 1][2] + pow5;
                    continue;
                }
                else if (zero_count + min(dp[j][K - 1][1] + pow2, dp[j][K - 1][2] + pow5) + dp[j][K - 1][0] <= dp[j][K][0] && dp[j][K][0] > dp[i][K][0])
                {
                    dp[i][K][0] = dp[j][K][0];
                    dp[i][K][1] = dp[j][K][1];
                    dp[i][K][2] = dp[j][K][2];
                    continue;
                }

                if (dp[i][K][0] < dp[i - 1][K][0])
                {
                    dp[i][K][0] = dp[i - 1][K][0];
                    dp[i][K][1] = dp[i - 1][K][1];
                    dp[i][K][2] = dp[i - 1][K][2];
                }
            }
    }
    cout << dp[n][k][0] << '\n';

    return 0;
}