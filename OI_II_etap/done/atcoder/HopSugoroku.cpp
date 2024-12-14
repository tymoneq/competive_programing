#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

constexpr int N = 2e5 + 10, NSQRT = 300, MOD = 998244353;

vector<int> dp(N, 1);
vector<vector<int>> s(NSQRT + 1, vector<int>(NSQRT + 1));

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int &w : A)
        cin >> w;

    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] > NSQRT)
            for (int j = i + A[i]; j < n; j += A[i])
            {
                dp[i] += dp[j];
                dp[i] %= MOD;
            }
        else
        {
            dp[i] += s[A[i]][i % A[i]];
            dp[i] %= MOD;
        }

        for (int j = 1; j <= NSQRT; j++)
        {
            s[j][i % j] += dp[i];
            s[j][i % j] %= MOD;
        }
    }
    cout << dp[0] << '\n';
    return 0;
}
