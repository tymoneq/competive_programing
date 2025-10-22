#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
public:
    inline void solve()
    {

        int N, ans = 0;
        cin >> N;
        vector<int> tableOfSizes(N + 1);
        vector<int> dp(N + 1, 1);

        FOR(i, N, 0)
        cin >> tableOfSizes[i + 1];

        dp[0] = 0;

        for (int item = 1; item <= N; item++)
            for (int prevItem = 1; prevItem * prevItem <= item; prevItem++)
            {
                int secondDiv = item / prevItem;
                if (tableOfSizes[prevItem] < tableOfSizes[item] && ((item % prevItem == 0)))
                    dp[item] = max(dp[item], dp[prevItem] + 1);

                if(tableOfSizes[secondDiv] < tableOfSizes[item] && (item % secondDiv == 0) && secondDiv < item)
                    dp[item] = max(dp[item], dp[secondDiv] + 1);
            }

        for (int i = 0; i <= N; i++)
            ans = max(ans, dp[i]);

        cout << ans << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        Solve s;
        s.solve();
    }

    return 0;
}