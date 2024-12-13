#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve()
{
    int n;
    ll sum = 0;
    ll Bessie = 0, Elsie = 0;

    cin >> n;
    vector<ll> cakes(n + 1), Pref(n + 1), Suf(n + 2);

    for (int i = 1; i <= n; i++)
    {
        cin >> cakes[i];
        Pref[i] = Pref[i - 1] + cakes[i];
        sum += cakes[i];
    }

    for (int i = n; i > 0; i--)
        Suf[i] = Suf[i + 1] + cakes[i];

    for (int i = 0; i <= (n / 2) - 1; i++)
    {
        int suf = n / 2 - 1 - i;

        Elsie = max(Elsie, Pref[i] + Suf[n - suf + 1]);
    }

    Bessie = sum - Elsie;
    cout << Bessie << " " << Elsie << '\n';
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