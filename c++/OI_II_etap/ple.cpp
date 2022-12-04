#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Base = 1 << 19;
ll Tree2[Base * 2];
void upd(int v, vector<ll> &Tree, ll to_add, int base)
{
    int V = v;
    int l = base;
    while (l / 2 != v / 2)
    {
        if (v % 2 == 1)
        {
            Tree[v - 1] += to_add;
            if (v < base)
                Tree2[v - 1] += to_add;
        }
        v /= 2;
        l /= 2;
    }
    if (l / 2 == v / 2 && l != v)
    {
        Tree2[l] += to_add;
        Tree[l] += to_add;
    }
    for (int i = V / 2; i > 0; i /= 2)
        Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]);
}
void findmax(ll val, int v, vector<ll> &Tree, vector<int> &Data, int base, int &Val) // p początek k koniec
{
    if (v >= base)
    {
        Tree[v] = numeric_limits<int>::min();
        Val = Data[v - base];
        upd(v, Tree, Data[v - base], base);
        return;
    }

    if (Tree[2 * v] == val || Tree[2 * v] + Tree2[v] == val)
    {
        Tree[2 * v] += Tree2[v];
        Tree[2 * v + 1] += Tree2[v];
        Tree2[2 * v] += Tree2[v];
        Tree2[2 * v+1] += Tree2[v];
        Tree2[v] = 0;
        findmax(val, v * 2, Tree, Data, base, Val);
    }

    else if (Tree[2 * v + 1] == val || Tree[2 * v + 1] + Tree2[v] == val)
    {
        Tree[2 * v + 1] += Tree2[v + 1];
        Tree[2 * v] += Tree2[v];
        Tree2[2 * v] += Tree2[v];
        Tree2[2 * v+1] += Tree2[v];
        Tree2[v] = 0;
        findmax(val, v * 2 + 1, Tree, Data, base, Val);
    }
}

inline bool my_sort(ll &lhs, ll &rhs) { return lhs < rhs; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int base = log2(n);
    if (!(pow(2, base) == n))
        base++;
    base = pow(2, base);
    vector<ll> Tree(base * 2);
    vector<ll> res;
    ll sum = 0;
    vector<int> Data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Data[i];
        sum += Data[i];
    }
    ll prev_sum = 0;
    for (int i = base; i < base + n; i++)
    {
        Tree[i] = 2 * Data[i - base] + prev_sum - sum;
        prev_sum += Data[i - base];
    }
    for (int i = base - 1; i > 0; i--)
        Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]);

    res.push_back(sum);
    int Val = 0;
    for (int i = 1; i < n; i++)
    {
        ll curent = Tree[1];
        findmax(curent, 1, Tree, Data, base, Val);
        res.push_back(res[i - 1] - Val);
    }
    sort(res.begin(), res.end(), my_sort);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    return 0;
}