#include <bits/stdc++.h>

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    while (n--)
    {
        int a;
        cin >> a;

        sum += a;

        int ans = 9 - (sum % 9);

        sum += ans;
        cout << ans << "\n";
        fflush(stdout);
    }

    return 0;
}