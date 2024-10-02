#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 5e5 + 10;
ll Pref[N], Suf[N];
int cnt[N], sums[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, left, right;
    ll sum_l = 0, sum_m = 0, sum_r = 0, ans = 0;
    cin >> n;
    vector<int> a(n);

    for (int &b : a)
    {
        cin >> b;
        sum_m += b;
    }
    Pref[0] = a[0];
    Suf[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
        Pref[i] = Pref[i - 1] + a[i];

    for (int i = n - 2; i >= 0; i--)
        Suf[i] = Suf[i + 1] + a[i];

    if (Suf[0] % 3 != 0 || n < 3)
        ans = 0;
    else
    {
        if (a[n - 1] * 3 == Pref[n - 1])
            cnt[n - 1] = 1;
        sums[n - 1] = cnt[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            cnt[i] = (Suf[0] == Suf[i] * 3 ? 1 : 0);
            sums[i] = sums[i + 1] + cnt[i];
        }
        ans = sums[2];
    }

    cout << ans << "\n";
    return 0;
}