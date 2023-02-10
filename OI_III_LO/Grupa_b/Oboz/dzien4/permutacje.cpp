#include <bits/stdc++.h>

using namespace std;
constexpr int M = 100, base = 1 << 3;
int Nums[M], Tree[base << 1], Count[M], Tree2[base << 1], start, n, val;

void upt(int v, int p, int k)
{
    if (p > n || k < start)
        return;
    if (p <= start && k <= n)
    {
        Tree[v] += val;
        Tree2[v] += val;
    }
    else
    {
        if (v > base)
            return;
        Tree2[2 * v] += val;
        Tree2[v] -= val;
        Tree2[2 * v + 1] += val;
        upt(v * 2, p, (p + k) / 2);
        upt(v * 2 + 1, (p + k) / 2 + 1, k);
    }
}
int querry(int v)
{
    int l = base;
    int r = v + base;
    int sum = Tree[base];
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
        {
            sum += Tree[l + 1];
            sum += Tree2[l + 1];
        }
        if (r % 2 == 1)
        {
            sum += Tree[r - 1];
            sum += Tree[r - 1];
        }
        r /= 2, l /= 2;
    }
    sum += Tree2[l] + Tree2[r];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> Cor;
    int a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> Nums[i];
        Tree[Nums[i] + base]++;
    }
    for (int i = base - 1; i > 0; i--)
        Tree[i] = Tree[2 * i] + Tree[2 * i + 1];
    for (int i = 1; i <= n; i++)
        Count[i] = Count[i - 1] + Tree[i + base];
    for (int i = n; i > 1; i--)
        if (Count[i - 1] > i - 1)
            Cor.insert(i - 1);

    int m, mn, mx;
    if (Cor.size() == 0)
        cout << "TAK\n";
    else
        cout << "NIE\n";
    cin >> m;
    int sum;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        val = -1;
        start = Nums[a];
        upt(1, 0, base);
        val = 1;
        start = b;
        upt(1, 0, base);
        Nums[a] = b;
        sum = querry(b);
        int xxd = 0;
    }
}