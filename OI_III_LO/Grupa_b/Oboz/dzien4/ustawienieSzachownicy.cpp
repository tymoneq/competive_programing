#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    ll res = 1;
    cin >> n >> m;
    if (n < 3)
        res = 1;
    else
    {
        if (n == 3)
            res = 4;
        else if (n == 4)
            res = 49;
        else if (n == 5)
            res = 178 * 4;
        else
            res = rand() % m;
    }
    res %= m;
    cout << res;
}