#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, a;
    cin >> n >> m >> a;

    ll res = 0;
    res = n / a;
    if (n % a != 0)
        res++;
    ll tmp = m / a;
    if (m % a != 0)
        tmp++;
    res *= tmp;
    cout << res << '\n';

    return 0;
}