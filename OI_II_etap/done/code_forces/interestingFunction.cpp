#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll N = 1e10;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    ll l, r, ans, prev;

    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        ans = 0;
        prev = 0;
        while (r > 0)
        {
            ans += (r - l);
            l /= 10, r /= 10;
        }

        cout << ans << "\n";
    }

    return 0;
}