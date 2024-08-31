#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAXN = 2e5 + 10;

ll Pref[MAXN], cnt[MAXN];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, l, r;
    ll tmp, ans;

    for (ll i = 0; i < MAXN; i++)
    {
        int n = i;
        tmp = 0;
        while (n)
        {
            tmp++;
            n /= 3;
        }
        cnt[i] = tmp;
        Pref[i + 1] = Pref[i] + cnt[i];
    }

    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        r++;
        ans = Pref[r] - Pref[l] + cnt[l];
        cout << ans << "\n";
    }

    return 0;
}