#include <bits/stdc++.h>
 
using namespace std;
 
int constexpr N = 2e5 + 10;
 
int dp[N], Suf[N];
vector<int> IndxTable[N];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t, n, indx;
    cin >> t;
 
    while (t--)
    {
        cin >> n;
        vector<int> Array(n);
        for (int i = 0; i < n; i++)
        {
            cin >> Array[i];
            IndxTable[Array[i]].push_back(i);
        }
        dp[n - 1] = 0;
        Suf[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = dp[i + 1];
            for (int j = IndxTable[Array[i]].size() - 1; IndxTable[Array[i]][j] > i; --j)
                dp[i] = max(dp[i], (IndxTable[Array[i]][j] - i + 1) + Suf[IndxTable[Array[i]][j] + 1]);
 
            Suf[i] = max(dp[i], Suf[i + 1]);
        }
 
        cout << dp[0] << "\n";
 
        for (int i = 0; i <= n; i++)
            dp[i] = 0, Suf[i] = 0, IndxTable[i].clear();
    }
 
    return 0;
}