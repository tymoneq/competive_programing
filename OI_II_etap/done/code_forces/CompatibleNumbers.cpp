#include <bits/stdc++.h>
#include <ext/pb_ds/hash_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

int constexpr MASK = 1 << 22;

int dp[MASK][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
    {
        cin >> a;
        dp[a][1] = 1;
        dp[a][0] = a;
    }

    for (int i = 0; i < 22; i++)
        for (int mask = 1; mask < MASK; mask++)
            if (mask & (1 << i) && dp[mask ^ (1 << i)][1])
            {
                dp[mask][1] = (dp[mask ^ (1 << i)][1] | dp[mask][1]);
                dp[mask][0] = dp[mask ^ (1 << i)][0];
            }
    for (int w : A)
    {
        if (dp[(MASK - 1) ^ w][1])
            cout << dp[(MASK - 1) ^ w][0] << ' ';
        else
            cout << -1 << ' ';
    }
    cout << '\n';

    return 0;
}