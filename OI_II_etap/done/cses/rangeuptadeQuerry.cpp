#include <bits/stdc++.h>

using namespace std;
constexpr int base = 1 << 19;
long long Tree[base << 1];
long long querry(int v)
{
    long long sum = 0;
    while (v > 0)
    {
        sum += Tree[v];
        v /= 2;
    }
    return sum;
}

void upt(int a, int b, int c)
{
    a--;
    a += base, b += base;
    b++;
    while (b - a > 1)
    {
        if (!(a & 1))
            Tree[a + 1] += c;

        if (b & 1)
            Tree[b - 1] += c;

        a >>= 1;
        b >>= 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, x, a, y, c;
    cin >> n >> q;
    for (int i = base + 1; i <= base + n; i++)
        cin >> Tree[i];
    for (int i = 0; i < q; i++)
    {
        cin >> a;
        if (a == 2)
        {
            cin >> x;
            cout << querry(x + base) << "\n";
        }
        else
        {
            cin >> x >> y >> c;
            upt(x, y, c);
        }
    }
    return 0;
}