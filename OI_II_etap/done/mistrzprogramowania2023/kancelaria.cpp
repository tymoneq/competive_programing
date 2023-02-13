#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
constexpr int base = 1 << 19, MOD = 1e9 + 7;
ll Tree[base << 1];
ll query(int v, int n)
{
    int l = v - 1, r = v + 1;
    ll res = 1;
    if (l < base)
        l = 0;
    if (r > base + n)
        r = 0;
    if (l != 0)
        res = Tree[l];
    res %= MOD;
    if (r != 0)
        res *= Tree[r];
    res %= MOD;
    while (l / 2 != r / 2)
    {
        if (l % 2 == 1)
            res *= Tree[l - 1];
        res %= MOD;
        if (r % 2 == 0)
            res *= Tree[r + 1];
        res %= MOD;
        l /= 2, r /= 2;
    }
    int mx = max(l / 2, r / 2);
    while (mx / 2 != 0)
    {

        if (mx % 2 == 1)
            res *= Tree[mx - 1];
        res %= MOD;
        if (mx % 2 == 0)
            res *= Tree[mx + 1];
        res %= MOD;
        mx /= 2;
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < base << 1; i++)
        Tree[i] = 1;
    for (int i = base; i < base + n; i++)
        cin >> Tree[i];
    for (int i = base - 1; i > 0; i--)
        Tree[i] = (Tree[2 * i] * Tree[2 * i + 1]) % MOD;
    for (int i = base; i < base + n; i++)
        cout << query(i, n) << " ";

    return 0;
}