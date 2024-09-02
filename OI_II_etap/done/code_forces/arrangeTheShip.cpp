#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAXN = 1e6 + 10;
ll Pref[MAXN], Suf[MAXN];
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    ll ans, sheeps;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> n >> s;
        sheeps = 0, ans = numeric_limits<ll>::max();

        if (s[0] == '*')
            sheeps++;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '.')
                Pref[i] = Pref[i - 1] + sheeps;
            else
            {
                Pref[i] = Pref[i - 1];
                sheeps++;
            }
        }
        sheeps = 0;

        if (s[n - 1] == '*')
            sheeps++;

        for (int i = n - 2; i >= 0; i--)
        {
            if (s[i] == '.')
                Suf[i] = Suf[i + 1] + sheeps;
            else
            {
                Suf[i] = Suf[i + 1];
                sheeps++;
            }
        }

        for (int i = 0; i < n; i++)
            ans = min(ans, Suf[i] + Pref[i]);

        cout << ans << "\n";

        for (int i = 0; i <= n; i++)
            Pref[i] = 0, Suf[i] = 0;
    }

    return 0;
}