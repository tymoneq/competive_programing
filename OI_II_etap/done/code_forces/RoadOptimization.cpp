#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 510;
ll dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, l;
    cin >> n >> l >> k;

    vector<ll> Times(n), cordinate(n);
    for (ll &a : cordinate)
        cin >> a;

    cordinate.push_back(l);

    for (ll &a : Times)
        cin >> a;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = numeric_limits<int>::max();

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
        {
            if (i == 0)
                dp[i][j] = Times[i] * (cordinate[i + 1] - cordinate[i]);

            else if (j == 0)
                dp[i][j] = Times[i] * (cordinate[i + 1] - cordinate[i]) + dp[i - 1][j];

            if (dp[i][j] == numeric_limits<int>::max())
                continue;

            for (int pos = i + 1; pos < n; pos++)
                dp[pos][j + pos - i - 1] = min(dp[pos][pos + j - i - 1], dp[i][j] + Times[i] * (cordinate[pos + 1] - cordinate[i]));
        }
    ll mn = numeric_limits<ll>::max();
    for (int i = 0; i <= k; i++)
        mn = min(mn, dp[n - 1][i]);

    cout << mn << '\n';

    return 0;
}