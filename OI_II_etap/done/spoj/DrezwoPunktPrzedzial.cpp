#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int base = 1 << 20;
ll Tree[base << 1];

void upt(int v, int val)
{
    Tree[v] = val;
    v /= 2;
    while (v != 0)
    {
        Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
        v /= 2;
    }
}
ll query(int l, int r)
{
    l += base, r += base;
    ll mx = max(Tree[l], Tree[r]);
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            mx = max(Tree[l + 1], mx);
        if (r % 2 == 1)
            mx = max(Tree[r - 1], mx);
        r /= 2, l /= 2;
    }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, p, k, val;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> p >> k;
        if (a == 0)
        {
            cin >> val;
            upt(p + base, val);
        }
        if (a == 1)
            cout << query(p, k) << "\n";
    }
    return 0;
}