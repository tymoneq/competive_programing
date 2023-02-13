#include <bits/stdc++.h>
using namespace std;
constexpr int base = 1 << 20;
long long Tree[base << 1];
void upt(int v)
{
    v /= 2;
    while (v > 0)
    {
        Tree[v] = max(Tree[2 * v], Tree[v * 2 + 1]);
        v /= 2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = base; i < base + n; i++)
        cin >> Tree[i];
    for (int i = base - 1; i > 0; i--)
        Tree[i] = max(Tree[i * 2], Tree[i * 2 + 1]);
    long long res = numeric_limits<long long>::min();
    long long tmp;
    for (int i = base; i < base + n; i++)
    {
        tmp = Tree[1] - Tree[i];
        res = max(res, tmp);
        Tree[i] = 0;
        upt(i);
    }
    if (res == 0)
        cout << "Nie ma zysku, to ci sie nie oplaca";
    else
        cout << res;
    return 0;
}