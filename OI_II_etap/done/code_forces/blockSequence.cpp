#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
int dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, mn;
    cin >> t;
    while (t--)
    {
        cin >> n;
        mn = numeric_limits<int>::max();
        vector<int> A(n);
        for (int &a : A)
            cin >> a;

        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (i + A[i] >= n)
                dp[i] = dp[i + 1] + 1;
            else
                dp[i] = min(dp[i + 1] + 1, dp[i + A[i] + 1]);
        }
        for (int i = 0; i < n; i++)
            dp[i] += i;

        for (int i = 0; i < n; i++)
            mn = min(mn, dp[i]);

        cout << mn << "\n";
        for (int i = 0; i <= n; i++)
            dp[i] = 0;
    }

    return 0;
}