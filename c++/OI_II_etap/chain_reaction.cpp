#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1e6 + 10;
int dp[MAX_VAL];
int Height[MAX_VAL];
int Position[MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, index, res = numeric_limits<int>::max();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Position[i] >> Height[i];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        l = Position[i] - Height[i];
        auto itr = lower_bound(Position, Position + i, l);
        index = itr - Position;
        if (Position[index] < l)
            dp[i] = dp[index] + i - index;
        else if (index - 1 < 0)
            dp[i] = dp[0] + i - index;
        else
            dp[i] = dp[index - 1] + i - index;
    }
    for (int i = 0; i < n; i++)
        res = min(res, dp[i] + n - i - 1);
    cout << res;
    return 0;
}
