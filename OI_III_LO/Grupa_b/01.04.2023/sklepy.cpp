#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
constexpr int M = 5e5 + 20, base = 1 << 19, INF = 1e8;
int LeftCost[M], RightCost[M], Cost[M];
int Tree[base << 1];
int v;
void findMin(int val)
{
    if (v > base)
        return;
    if (Tree[2 * v] == val)
    {
        v *= 2;
        findMin(val);
    }
    else
    {
        v *= 2;
        v++;
        findMin(val);
    }
}
void upt(int ver)
{
    ver /= 2;
    while (ver > 0)
    {
        Tree[ver] = min(Tree[ver * 2], Tree[ver * 2 + 1]);
        ver /= 2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ull res = 0;
    vector<int> Order;
    for (int i = 1; i <= n; i++)
        cin >> Cost[i];
    for (int i = 1; i < n; i++)
        cin >> RightCost[i];
    for (int i = 2; i <= n; i++)
        cin >> LeftCost[i];
    for (int i = base; i < base + base; i++)
        Tree[i] = INF;
    for (int i = base + 1; i <= base + n; i++)
        Tree[i] = LeftCost[i - base] + RightCost[i - base];
    for (int i = base - 1; i > 0; i--)
        Tree[i] = min(Tree[2 * i], Tree[2 * i + 1]);

    for (int i = 0; i < n; i++)
    {
        v = 1;
        findMin(Tree[1]);
        int shopID = v - base;
        Order.push_back(shopID);
        res += Cost[shopID];
        Cost[shopID + 1] += RightCost[shopID];
        Cost[shopID - 1] += LeftCost[shopID];
        shopID += base;
        Tree[shopID - 1] -= RightCost[shopID - base - 1];
        Tree[shopID + 1] -= LeftCost[shopID - base + 1];
        Tree[shopID] = INF;
        upt(shopID);
        upt(shopID - 1);
        upt(shopID + 1);
    }
    cout << res << "\n";
    for (int w : Order)
        cout << w << " ";
    return 0;
}