#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, k, n, m, ans, a;

    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;

        ans = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a;
            if (a == (n + k - 1) / k)
                ans++;
            if (a > (n + k - 1) / k)
                ans = 1 << 30;
        }
        cout << (ans <= (n - 1) % k + 1 ? "YES\n" : "NO\n");
    }

    return 0;
}