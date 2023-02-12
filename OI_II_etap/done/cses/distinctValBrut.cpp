#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10;
int Val[M];
int Bit[M];
void upt(int v, int val)
{
    v++;
    while (v <= M)
    {
        Bit[v] += val;
        v += (v & (-v));
    }
}
int query(int v)
{
    int sum = 0;
    v++;
    while (v > 0)
    {
        sum += Bit[v];
        v -= (v & (-v));
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> Val[i];
    vector<vector<pair<int, int>>> Queries(n);
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--, b--;
        Queries[a].push_back({b, i});
    }
    map<int, int> last_ind;
    vector<int> Res(q, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        int val = Val[i];
        if (last_ind.count(val) > 0)
            upt(last_ind[val], -1);
        last_ind[val] = i;
        upt(i, 1);
        for (auto &qr : Queries[i])
            Res[qr.second] = query(qr.first);
    }
    for (int &w : Res)
        cout << w << "\n";
    return 0;
}