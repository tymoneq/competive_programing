#include <bits/stdc++.h>

using namespace std;
constexpr int MAX_N = 2e5 + 10, bits = 30;
int Numb[MAX_N];
int PrefSum[MAX_N][bits];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, q, l, k, sum, ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> Numb[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < bits; j++)
            {
                if (Numb[i] & (1 << j))
                    PrefSum[i + 1][j] = PrefSum[i][j] + 1;
                else
                    PrefSum[i + 1][j] = PrefSum[i][j];
            }
        cin >> q;
        for (int i = 0; i < q; i++)
        {

            cin >> l >> k;
            if (Numb[l-1] < k)
            {
                cout << -1 << " ";
                continue;
            }

            int lo, hi, mid;
            lo = l, hi = n;
            ans = l;
            while (lo <= hi)
            {
                mid = lo + (hi - lo) / 2;
                sum = 0;
                for (int j = 0; j < bits; j++)
                    if (PrefSum[mid][j] - PrefSum[l - 1][j] == mid - l + 1)
                        sum += (1 << j);

                if (sum >= k)
                {
                    lo = mid + 1;
                    ans = max(ans, mid);
                }
                else
                    hi = mid - 1;
            }
            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}