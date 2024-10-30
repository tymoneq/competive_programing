#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int N = 1e5 + 10;
constexpr ll INF = 1e17;

ll n, a, b, d;
ll dp[N];

inline ll f(ll w, ll v)
{
    return (w * a + b * v) % 1001;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> a >> b;
    for (int i = 1; i <= n; i++)
        dp[i] = INF;

    dp[1] = 0;

    for (int x = 2; x <= n; x++)
    {
        for (int i = (x - d) / 2; i <= (x + d) / 2; i++)
        {
            int j = x - i;
            dp[x] = min(dp[x], dp[i] + dp[j] + f(i, j));
        }
    }
    cout << dp[n] << "\n";
    return 0;
}