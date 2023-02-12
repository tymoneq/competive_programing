#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7, M = 2e5 + 10;
typedef long long ll;
int n;
ll bit[M];
ll query(int i)
{
    ll res = 0;
    for (; i; i -= (i & (-i)))
        res = (res + bit[i]) % MOD;
    return res;
}
void upt(int i, int val)
{
    for (; i <= n; i += (i & (-i)))
        bit[i] += val, bit[i] %= MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll sum = 0;
    map<int, int> m;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        m[ar[i]]++;
    }
    int co = 0;
    for (auto &cur : m)
        cur.second = ++co;
    for (int &x : ar)
        x = m[x];

    for (int x : ar)
    {
        int subseq = 1 + query(x - 1);
        sum += subseq;
        sum %= MOD;
        upt(x, subseq);
    }
    cout << sum;
}