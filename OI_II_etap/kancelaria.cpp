#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int base = 1 << 4, MOD = 1e9 + 7;
ll Tree[base << 1];
ll query(int v, int n)
{
    int l = v - 1, r = v + 1;
    ll res = 1;
    if (v % 2 == 0)
    {
        res = Tree[v + 1];
        r++;
    }
    else if (v % 2 != 0)
    {
        res = Tree[v - 1];
        l--;
    }
    if (l < base)
        l = 0;
    if (r > base + n)
        r = 0;

    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            res *= Tree[l];
        if (r % 2 == 1)
            res *= Tree[r];
        res %= MOD;
        l /= 2, r /= 2;
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
    {
        cout << query(i, n) << " ";
    }
    return 0;
}