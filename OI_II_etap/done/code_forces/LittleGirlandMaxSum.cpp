#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int base = 1 << 18;
int Tree[base << 1];

void add(int l, int r, int x)
{
    l += base - 1;
    r += base + 1;

    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            Tree[l + 1] += x;
        if (r % 2 == 1)
            Tree[r - 1] += x;

        l /= 2, r /= 2;
    }
}
int fint()
{
    int indx = 1;

    while (indx < base)
    {
        if (Tree[indx * 2] == Tree[indx])
            indx *= 2;
        else
            indx = indx * 2 + 1;
    }

    return indx;
}

void upt(int v)
{
    Tree[v] = 0;
    v /= 2;
    while (v > 0)
    {
        Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
        v /= 2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, l, r, indx;
    ll res = 0;
    cin >> n >> q;
    vector<ll> a(n);

    for (ll &b : a)
        cin >> b;

    sort(a.begin(), a.end(), greater<ll>());

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        add(l, r, 1);
    }
    for (int i = 1; i < base; i++)
    {
        Tree[2 * i] += Tree[i];
        Tree[2 * i + 1] += Tree[i];
        Tree[i] = 0;
    }
    for (int i = base - 1; i > 0; i--)
        Tree[i] = max(Tree[i * 2], Tree[i * 2 + 1]);

    for (ll el : a)
    {
        res += Tree[1] * el;
        indx = fint();
        upt(indx);
    }

    cout << res << "\n";
    return 0;
}