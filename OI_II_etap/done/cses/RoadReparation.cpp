#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 1e5 + 10;
int R[M], fa, fb, countt;
ll res;
struct edge
{
    int l, r, Val;
};
vector<int> Graph[M];
inline bool sortEdge(edge &lhs, edge &rhs) { return lhs.Val < rhs.Val; }
int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
void onion(int a, int b, int c)
{
    fa = fint(a);
    fb = fint(b);
    if (fa == fb)
        return;
    R[fa] = fb;
    res += c;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
}

void dfs(int v, int p)
{
    countt--;
    for (int w : Graph[v])
        if (w != p)
            dfs(w, v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        R[i] = i;
    vector<edge> E(m);
    for (int i = 0; i < m; i++)
        cin >> E[i].l >> E[i].r >> E[i].Val;
    sort(E.begin(), E.end(), sortEdge);
    for (auto w : E)
        onion(w.l, w.r, w.Val);
    countt = n;
    dfs(1, 1);
    if (countt == 0)
        cout << res;
    else
        cout << "IMPOSSIBLE";
    return 0;
}