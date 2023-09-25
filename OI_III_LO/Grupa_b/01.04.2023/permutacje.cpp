#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e5 + 10, base = 1 << 18;
int Num[M], Val[M], Path[M];
int Tree[base << 1];
void upt(int v)
{
    v /= 2;
    while (v != 0)
    {
        Tree[v] = max(Tree[v * 2], Tree[2 * v + 1]);
        v /= 2;
    }
}
int querry(int v)
{
    int l = base, r = v + base, mx = 0;
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            mx = max(mx, Tree[l + 1]);
        if (r % 2 == 1)
            mx = max(mx, Tree[r - 1]);
        r /= 2, l /= 2;
    }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> Res;
    for (int i = 0; i < n; i++)
        cin >> Num[i];
    Val[0] = 1;
    Tree[Num[0] + base] = 1;
    upt(base + Num[0]);
    for (int i = 1; i < n; i++)
    {
        Val[i] = querry(Num[i]) + 1;
        Tree[base + Num[i]] = Val[i];
        upt(base + Num[i]);
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, Val[i]);
    unordered_map<int, int> m;
    for (int i = n - 1; i >= 0; i--)
    {
        if (m[Val[i] + 1] > Num[i])
        {
            Res.insert(Num[i]);
            m[Val[i]] = max(m[Val[i]], Num[i]);
        }
        else if (Val[i] == mx)
        {
            Res.insert(Num[i]);
            m[mx] = max(Num[i], m[mx]);
        }
    }
    cout << Res.size() << "\n";
    for (int w : Res)
        cout << w << " ";
    return 0;
}