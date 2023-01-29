#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fast_pot(ll n, ll w)
{
    ll a = 1;
    while (w > 0)
    {
        if (w % 2 == 1)
        {
            a *= n;
            a %= 1000000007;
        }
        n *= n;
        n %= 1000000007;
        w /= 2;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, res = 0;
    cin >> n >> k;

    res = fast_pot(2, k - 1);
    cout << res;
    return 0;
}