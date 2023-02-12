#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    long long mx = 0, s = 0, x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mx = max(mx, x);
        s += x;
    }
    cout << max(2 * mx, s);
    return 0;
}