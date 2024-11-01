#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, mx = 0;
    ll sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
        mx = max(mx, a);
    }

    cout << ((sum % 2 == 0 && sum - mx >= mx) ? "YES" : "NO") << "\n";
    return 0;
}