#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void upd(int v, int x, vector<ll> &Tree)
{
    Tree[v] = x;
    int tmp = v / 2;
    while (tmp > 0)
    {
        Tree[tmp] = Tree[tmp * 2] + Tree[tmp * 2 + 1];
        tmp /= 2;
    }
}
ll get_value(int l, vector<ll> &Tree, int base, int n)
{
    ll sum = 0;
    int val = Tree[l];
    l += 1;
    if (l == Tree.size())
        return 0;
    int r = base + n;
    sum += Tree[l];
    while (l / 2 != r / 2)
    {
        if (val - sum <= 0)
            break;
        if (l % 2 == 0)
            sum += Tree[l + 1];

        if (r % 2 == 1)
            sum += Tree[r - 1];
        l /= 2;
        r /= 2;
    }
    return sum;
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
    vector<ll> res(n);
    ll sum = 0;
    for (int i = base; i < base + n; i++)
        cin >> Tree[i];

    for (int i = base - 1; i > 0; i--)
        Tree[i] = Tree[2 * i] + Tree[2 * i + 1];

    sum = Tree[1];
    res[0] = sum;
    for (int i = 1; i < n; i++)
        for (int j = base; j < base + n; j++)
        {
            if (Tree[j] == 0)
                continue;
            ll left_sum = get_value(j, Tree, base, n);
            if (Tree[j] - left_sum > 0)
            {
                res[i] = res[i - 1] - Tree[j];
                upd(j, 0, Tree);
                break;
            }
        }

    sort(res.begin(), res.end(), my_sort);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    return 0;
}