#include <bits/stdc++.h>

using namespace std;
// usunięcie ostaniego istotnego bitu V-=(V&(-V))
constexpr int N = 10000;
int Tree[N];
int querry(int v)
{
    int res = 0;
    while (v > 0)
    {
        res += Tree[v];
        v -= (v & (-v));
    }
    return v;
}
void upt(int v, int val)
{
    while (v <= N)
    {
        Tree[v] += val;
        v += (v & (-v));
    }
}
