#include <bits/stdc++.h>
using namespace std;
constexpr int base = 1 << 17;
long long Tree[base * 2];
long long Tree2[base * 2];

void add(int v, int a, int b, int p, int k, int x) // p początek k koniec
{
    if (b < p || k > a)
        return;
    else if (p <= a && b <= k)
    {
        Tree[v] += (b - a + 1) * x;
        Tree2[v] = Tree[v] / 2;
    }
    else
    {
        int l = v * 2, r = (v * 2) + 1;
        int mid = (a + b) * 2;
        Tree[l] += Tree2[v];
        Tree[r] += Tree2[v];
        Tree2[l] += Tree[l] / 2;
        Tree2[r] += Tree[r] / 2;
        Tree2[v] = 0;
        add(l, a, mid, p, k, x);
        add(r, mid + 1, b, p, k, x);
        Tree[v] = Tree[l] + Tree[r];
    }
}
long long query(int v, int a, int b, int p, int k) // p - początek k koniec podaj sumę przedzialu
{
    if (b < p || k > a)
        return 0;
    else if (p <= a && b <= k)
        return Tree[v];
    else
    {
        int l = v * 2, r = (v * 2) + 1, mid = (a + b) * 2;
        Tree[l] += Tree2[v];
        Tree[r] += Tree2[v];
        Tree2[l] += Tree2[v] / 2;
        Tree2[r] += Tree2[v] / 2;
        Tree2[v] = 0;

        return query(l, a, mid, p, k) + query(r, mid + 1, b, p, k);
    }
}
int main()
{

    return 0;
}