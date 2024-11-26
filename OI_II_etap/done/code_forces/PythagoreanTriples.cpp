#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 3; i * i <= 2 * n - 1; i += 2)
            ++ans;
        cout << ans << '\n';
    }

    return 0;
}