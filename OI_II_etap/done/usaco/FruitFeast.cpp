#include <bits/stdc++.h>

using namespace std;
constexpr int M = 5e6+10;
int dp[M];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);

    fin.open("feast.in"), fout.open("feast.out");
    int t, a, b;
    fin >> t >> a >> b;
    for (int i = 1; i <= t; i++)
    {
        if (i - a >= 0)
            dp[i] = max(dp[i - 1], dp[i - a] + a);
        if (i - b >= 0)
            dp[i] = max(max(dp[i - 1], dp[i]), dp[i - b] + b);
        else if (i - a < 0 && i - b < 0)
            dp[i] = dp[i - 1];
    }
    int prev_dp = dp[t];
    dp[dp[t] / 2] = dp[t] / 2;
    for (int i = dp[t] / 2 + 1; i <= t; i++)
    {
        if (i - a >= 0)
            dp[i] = max(max(dp[i - 1], dp[i]), dp[i - a] + a);
        if (i - b >= 0)
            dp[i] = max(max(dp[i - 1], dp[i]), dp[i - b] + b);
        else if (i - a < 0 && i  - b < 0)
            dp[i] = dp[i - 1];
    }
    fout << max(dp[t], prev_dp);
    fin.close(), fout.close();
    return 0;
}