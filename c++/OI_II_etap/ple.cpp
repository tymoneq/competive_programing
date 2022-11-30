#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll uptd_val(vector<ll> &Tree, int base, int v, int val, vector<ll> &data)
{

    while (v < base)
    {
        if (Tree[2 * v] == val)
            v *= 2;
        else
            v = v * 2 + 1;
    }
    Tree[v] = 0;
    ll sum = data[v - base + 1];
    for (int i = base; i < v; i++)
        Tree[i] += data[v - base + 1];
    for (int i = v / 2; i > 0; i--)
    {
        if (Tree[i * 2] > 0 || Tree[i * 2 + 1] <= 0)
            Tree[i] = Tree[2 * i];
        else
            Tree[i] = Tree[2 * i + 1];
    }
    return sum;
}
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
    vector<ll> data(n + 1);
    vector<ll> Tree(base * 2);
    vector<ll> res(n);
    ll sum = 0;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> data[i];
        sum += data[i];
    }

    int index = 1;
    ll prev_sum = 0;
    for (int i = base; i < base + n; i++)
    {
        Tree[i] = data[index] - sum + data[index] + prev_sum;
        prev_sum += data[index];
        index++;
    }
    for (int i = base - 1; i > 0; i--)
    {
        if (Tree[i * 2] > 0 || Tree[i * 2 + 1] == 0)
            Tree[i] = Tree[2 * i];
        else
            Tree[i] = Tree[2 * i + 1];
    }

    res[0] = sum;
    for (int i = 1; i < n; i++)
    {
        ll tmp = uptd_val(Tree, base, 1, Tree[1], data);
        res[i] = res[i - 1] - tmp;
    }

    for (int i = n - 1; i >= 0; i--)
        cout << res[i] << " ";
    return 0;
}