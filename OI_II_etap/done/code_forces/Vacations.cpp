#include <bits/stdc++.h>

using namespace std;

constexpr int N = 110;

int dp[N][3]; // stan 0 - > odpoczynek stan 1 -> kodowanie stan 2 - > siłka

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;

    cin >> n;

    vector<int> days(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> days[i];

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        if (days[i] == 1 || days[i] == 3)
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;

        if (days[i] == 2 || days[i] == 3)
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
    }
    int mx = 0;
    for (int i = 0; i < 3; i++)
        mx = max(mx, dp[n][i]);

    cout << n - mx << "\n";
    return 0;
}