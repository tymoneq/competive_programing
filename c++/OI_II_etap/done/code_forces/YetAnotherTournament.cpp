#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> m;
        vector<int> PreperingTime(n);
        for (int i = 1; i <= n; i++)
        {
            cin >> PreperingTime[i - 1];
        }
        auto B = PreperingTime;
        sort(PreperingTime.begin(), PreperingTime.end());
        int res = 0;
        for (int i = 0; i < n && PreperingTime[i] <= m; i++)
        {
            m -= PreperingTime[i];
            res++;
        }
        if (res != 0 && res != n && m + PreperingTime[res - 1] >= B[res])
            res++;
        cout << n + 1 - res << "\n";
    }
    return 0;
}