#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e5 + 10;
struct edge
{
    int l, r, Val;
};
struct query
{
    int k, V, i;
};

int Res[M], Sajz[M], R[M];
inline bool sortoo(edge &lhs, edge &rhs) { return lhs.Val > rhs.Val; }
inline bool sortQuery(query &lhs, query &rhs) { return lhs.k > rhs.k; }
int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
int finta, fintb;
void onion(int a, int b)
{
    finta = fint(a), fintb = fint(b);
    if (finta == fintb)
        return;
    if (Sajz[finta] > Sajz[fintb])
        swap(finta, fintb);
    Sajz[fintb] += Sajz[finta];
    Sajz[finta] = 0;
    R[finta] = fintb;
}
int main()
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<edge> E(n - 1);
    vector<query> Q(q);
    for (int i = 1; i <= n; i++)
    {
        Sajz[i] = 1;
        R[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
        cin >> E[i].l >> E[i].r >> E[i].Val;
    sort(E.begin(), E.end(), sortoo);
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].k >> Q[i].V;
        Q[i].i = i;
    }
    sort(Q.begin(), Q.end(), sortQuery);
    int ind = 0, f;
    for (auto w : E)
    {
        while (w.Val < Q[ind].k)
        {
            f = fint(Q[ind].V);
            Res[Q[ind].i] = Sajz[f] - 1;
            ind++;
        }
        onion(w.l, w.r);
    }
    while (ind < q)
    {
        f = fint(Q[ind].V);
        Res[Q[ind].i] = Sajz[f] - 1;
        ind++;
    }

    for (int i = 0; i < q; i++)
        cout << Res[i] << "\n";
    return 0;
}