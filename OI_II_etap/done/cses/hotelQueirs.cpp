#include <bits/stdc++.h>

using namespace std;
const int base = 1 << 19;
int Tree[base << 1], val;
inline void upt(int v)
{
    v /= 2;
    while (v > 0)
    {
        Tree[v] = max(Tree[v * 2], Tree[2 * v + 1]);
        v /= 2;
    }
}
inline void querry(int v)
{
    if (v >= base)
    {
        cout << v - base + 1 << " ";
        Tree[v] -= val;
        upt(v);
        return;
    }
    else if (Tree[2 * v] >= val)
        querry(2 * v);
    else if (Tree[2 * v + 1] >= val)
        querry(2 * v + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = base; i < base + n; i++)
        cin >> Tree[i];
    for (int i = base - 1; i > 0; i--)
        Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]);
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        if (val > Tree[1])
            cout << 0 << " ";
        else
            querry(1);
    }
    return 0;
}