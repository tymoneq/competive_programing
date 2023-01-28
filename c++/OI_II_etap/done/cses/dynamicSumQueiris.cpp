#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int base = 1 << 19;
ll Tree[base << 1];
inline void upd(int v)
{
    v /= 2;
    while (v > 0)
    {
        Tree[v] = Tree[2 * v] + Tree[2 * v + 1];
        v /= 2;
    }
}
inline ll querry(int l, int r)
{
    long long res = 0;
    l += base - 1, r += base - 1;
    res += Tree[l];
    if (r != l)
        res += Tree[r];
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            res += Tree[l + 1];
        if (r % 2 == 1)
            res += Tree[r - 1];
        l /= 2, r /= 2;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, n, q, z;
    cin >> n >> q;
    for (int i = base; i < base + n; i++)
        cin >> Tree[i];
    for (int i = base - 1; i > 0; i--)
        Tree[i] = Tree[2 * i] + Tree[2 * i + 1];
    for (int i = 0; i < q; i++)
    {
        cin >> z >> a >> b;
        if (z == 1)
        {
            Tree[base + a - 1] = b;
            upd(base + a - 1);
        }
        else if (z == 2)
            cout << querry(a, b) << "\n";
    }
    return 0;
}