#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MASK = 1 << 20;

ll dp[20][MASK];

int main()
{
    int n = 20;

    vector<int> A(MASK);

    for (int i = 0; i < MASK; i++)
        cin >> A[i];

    for (int i = 0; i < MASK; i++)
        dp[0][i] = A[i];
    for (int i = 1; i <= n; i++)
        for (int mask = 0; mask < MASK; mask++)
        {
            if (mask & (1 << (i - 1)))
                dp[i][mask] = dp[i - 1][mask ^ (1 << (i - 1))] + dp[i - 1][mask];

            else
                dp[i][mask] = dp[i - 1][mask];
        }
    return 0;
}