#include <bits/stdc++.h>

using namespace std;

inline bool valid(int depth)
{
}

inline void solve()
{
    int n;
    cin >> n;

    int lo = 1, hi = n, mid, ans = numeric_limits<int>::max();

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (valid(mid))
        {
            hi = mid - 1;
            ans = mid;
        }
        else
            lo = mid + 1;
    }
    cout << ans << "\n";
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