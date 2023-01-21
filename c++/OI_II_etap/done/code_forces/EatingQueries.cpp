#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, q, a, hi, lo, mid, res;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> q;
        vector<int> Sweets(n);
        vector<long long> Prefsum(n);
        for (int i = 0; i < n; i++)
            cin >> Sweets[i];
        sort(Sweets.begin(), Sweets.end(), greater<int>());
        Prefsum[0] = Sweets[0];
        for (int i = 1; i < n; i++)
            Prefsum[i] = Prefsum[i - 1] + Sweets[i];
        for (int i = 0; i < q; i++)
        {
            cin >> a;
            lo = 1, hi = n;
            if (a > Prefsum[n - 1])
                cout << -1 << "\n";
            else
            {
                while (lo <= hi)
                {
                    mid = (lo + hi) / 2;
                    if (Prefsum[mid - 1] >= a)
                        hi = mid - 1, res = mid;
                    else
                        lo = mid + 1;
                }
                cout << res << "\n";
            }
        }
    }
    return 0;
}