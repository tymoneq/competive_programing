#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, b, c;
        ll ans = 0;
        cin >> n >> b >> c;
        if (b == 0 && c == 0)
            cout << -1 << "\n";
        else if (b == 0)
        {
            if (c + 2 >= n)
                cout << n - 1 << "\n";
            else
                cout << -1 << '\n';
        }
        else
        {
            ll lo = 0, mid, hi;

            hi = n / (max(b, (ll)1)) + 10;
            while (lo <= hi)
            {
                mid = lo + (hi - lo) / 2;
                if (b * (mid - 1) + c < n)
                {
                    ans = mid;
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }

            cout << n - ans << "\n";
        }
    }

    return 0;
}