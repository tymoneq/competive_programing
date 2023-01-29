#include <bits/stdc++.h>
using namespace std;
const int MAX_VAL = 1e5 * 2 + 10;

int TAB[MAX_VAL];
int dp[MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, n, res = 0, tmp = 0, aktual_res = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        res = 0;
        for (int j = 1; j <= n; j++)
            cin >> TAB[j];
        for (int j = n; j > 0; j--)
        {
            tmp = j + TAB[j];
            aktual_res = TAB[j];
            if (tmp > n)
                dp[j] = aktual_res;
            while (tmp <= n)
            {
                if (dp[tmp] != 0)
                {
                    dp[j] = dp[tmp] + aktual_res;
                    break;
                }
                aktual_res += TAB[tmp];
                tmp += TAB[tmp];
            }
            res = max(res, dp[j]);
        }
        cout << res << "\n";
    }

    return 0;
}