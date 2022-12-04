#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Base = 1 << 20;
ll Tree2[Base * 2];
void addmax(int v, int a, int b, int p, int k, int x, vector<ll> &Tree, int &base) // p początek k koniec
{
    if (b < p || k < a)
        return;
    else if (p <= a && b <= k)
    {
        if (b == k && v < base)
        {
            Tree[v * 2] += x;
            Tree2[v * 2] += x;
            k += base;
            while (k / 2 != v)
            {
                Tree[k - 1] += x;
                if (k < base)
                    Tree2[k - 1] += x;
                k /= 2;
            }
        }
        else if (v < base)
        {
            Tree[v] += x;
            Tree2[v] += x;
        }
    }
    else
    {
        int l = v * 2, r = (v * 2) + 1;
        int mid = (a + b) / 2;
        addmax(l, a, mid, p, k, x, Tree, base);
        addmax(r, mid + 1, b, p, k, x, Tree, base);
    }
}
void upd(vector<ll> &Tree, int v)
{
    while (v != 1)
    {
        v /= 2;
        v *= 2;
        Tree[v / 2] = max(Tree[v], Tree[v + 1]);
        v /= 2;
    }
}
void findmax(ll val, int v, vector<ll> &Tree, vector<int> &Data, int base, int &Val, int &n) // p początek k koniec
{
    if (v >= base)
    {
        Tree[v] = numeric_limits<ll>::min();
        Val = Data[v - base];
        addmax(1, 0, n, 0, v - base, Val, Tree, base);
        upd(Tree, v);
        return;
    }

    if (Tree[2 * v] + Tree2[v] == val)
    {
        Tree[2 * v] += Tree2[v];
        Tree[2 * v + 1] += Tree2[v];
        Tree2[2 * v] += Tree2[v];
        Tree2[2 * v + 1] += Tree2[v];
        Tree2[v] = 0;
        findmax(val, v * 2, Tree, Data, base, Val, n);
    }

    else if (Tree[2 * v + 1] + Tree2[v] == val)
    {
        Tree[2 * v] += Tree2[v];
        Tree[2 * v + 1] += Tree2[v];
        Tree2[2 * v] += Tree2[v];
        Tree2[2 * v + 1] += Tree2[v];
        Tree2[v] = 0;
        findmax(val, v * 2 + 1, Tree, Data, base, Val, n);
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
    for (int i = base + n; i < base * 2; i++)
        Tree[i] = numeric_limits<ll>::min();
    for (int i = base - 1; i > 0; i--)
        Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]);

    res.push_back(sum);
    int Val = 0;
    for (int i = 1; i < n; i++)
    {
        ll curent = Tree[1];
        findmax(curent, 1, Tree, Data, base, Val, n);
        res.push_back(res[i - 1] - Val);
    }
    sort(res.begin(), res.end(), my_sort);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    return 0;
}