#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, MOD, n;
    cin >> A >> B >> MOD;
    ll res = 0;

    n = A * B - 1;

    vector<int> permutations(n);
    for (int i = 1; i <= n; i++)
        permutations[i - 1] = i;

    cout << res << "\n";

    do
    {
        int uppperbound = numeric_limits<int>::max(), lowerBound = 0;
        bool T = 1;
        
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
                if (permutations[j] < permutations[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (dp[i] > A)
            {
                T = 0;
                break;
            }
            if (dp[i] == A)
                uppperbound = min(uppperbound, permutations[i]);
        }

        if (!T)
            continue;

        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
                if (permutations[j] > permutations[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (dp[i] > B)
            {
                T = 0;
                break;
            }
            if (dp[i] == B)
                lowerBound = max(lowerBound, permutations[i]);
        }

        if (!T)
            continue;

        if (lowerBound < uppperbound)
        {
            res++;
            res %= MOD;
        }

    } while (next_permutation(permutations.begin(), permutations.end()));

    cout << res << "\n";
    return 0;
}