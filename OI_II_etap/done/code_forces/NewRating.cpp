#include <bits/stdc++.h>

using namespace std;

inline void solve()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<vector<int>> dp(n, vector<int>(3, 0));
    // stany w dp
    // 0 -> zysk bez usuwania
    // 1 -> zysk z usuwaniem
    //  2-> zysk z usuwaniem + wrócenie do normalnego dodawania

    for (int &a : A)
        cin >> a;

    dp[0][0] = 1;
    // calulating dp
    for (int i = 1; i < n; i++)
    {
        // liczenie stanu 0
        if (dp[i - 1][0] == A[i])
            dp[i][0] = dp[i - 1][0];
        else if (dp[i - 1][0] > A[i])
            dp[i][0] = dp[i - 1][0] - 1;
        else if (dp[i - 1][0] < A[i])
            dp[i][0] = dp[i - 1][0] + 1;

        // liczenie stanu 1
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);

        // liczenie stanu 2
        int val1 = 0, val2 = 0;
        if (dp[i - 1][2] > A[i])
            val1--;
        else if (dp[i - 1][2] < A[i])
            val1++;

        if (dp[i - 1][1] > A[i])
            val2--;
        else if (dp[i - 1][1] < A[i])
            val2++;

        dp[i][2] = max(dp[i - 1][2] + val1, dp[i - 1][1] + val2);
    }

    int mx = max(dp[n - 1][1], dp[n - 1][2]);
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}