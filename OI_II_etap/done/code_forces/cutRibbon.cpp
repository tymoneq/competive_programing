#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, z = 0, ans = 0;
    vector<int> Ribbon(4);
    cin >> n;

    for (int i = 0; i < 3; i++)
        cin >> Ribbon[i];

    for (int x = 0; x <= n; x++)
        for (int y = 0; y <= n; y++)
            if (Ribbon[0] * x + Ribbon[1] * y <= n)
            {
                z = (n - x * Ribbon[0] - y * Ribbon[1]) / Ribbon[2];
                if ((z+x+y) != 0 && n % (z * Ribbon[2] + y * Ribbon[1] + x * Ribbon[0]) == 0)
                    ans = max(ans, z + y + x);
            }

    cout << ans << "\n";
    return 0;
}