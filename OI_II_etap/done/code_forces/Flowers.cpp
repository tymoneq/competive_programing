#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1e5 + 10;
constexpr ll MOD = 1e9 + 7;
ll dp[N];
ll Pref[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, k;
    cin >> t >> k;
    dp[0] = 1;

    for (int i = 1; i < N; i++)
    {
        if (i < k)
            dp[i] += 1;
        else
            dp[i] += dp[i - 1] + dp[i - k];

        dp[i] %= MOD;
    }

    Pref[1] = dp[1];
    for (int i = 2; i < N; i++)
        Pref[i] = (Pref[i - 1] + dp[i]) % MOD;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        ll ans = (MOD + Pref[b] - (Pref[a - 1])) % MOD;

        cout << ans << "\n";
    }

    return 0;
}