#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

constexpr int N = 1e5 + 10, NSQRT = 300;

int Ans[N];
int dp[100001 + NSQRT][NSQRT];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    while (k--)
    {
        int a, l, d;
        cin >> a >> l >> d;

        if (d < NSQRT)
        {
            dp[a][d]++;
            dp[a + (l * d)][d]--;
        }

        else
        {
            for (int i = 0; i < l; i++)
                Ans[a + i * d]++;
        }
    }

    for (int j = 1; j < NSQRT; j++)
        for (int i = j; i < n + 1; i++)
            dp[i][j] += dp[i - j][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j < NSQRT; j++)
            Ans[i] += dp[i][j];

    for (int i = 1; i <= n; i++)
        cout << Ans[i] << " ";
    cout << '\n';

    return 0;
}