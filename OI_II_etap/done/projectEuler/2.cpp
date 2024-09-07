#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 1e7;

ll dp[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll res = 0;
    int i = 2;
    dp[1] = 1;
    while (dp[i - 1] < 4000000)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] % 2 == 0)
            res += dp[i];
        i++;
    }

    cout << res << "\n";
}