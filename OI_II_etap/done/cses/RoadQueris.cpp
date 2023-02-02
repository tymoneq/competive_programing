#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10, L = 18;
struct edge
{
    int start, end, val;
};
int par[M][L], R[M], Depth[M], Cost[M][L];
edge E[M];
vector<pair<int, int>> Mst[M];
inline int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
inline void onion(int a, int b, int val)
{
    if (fint(a) == fint(b))
        return;
    R[fint(b)] = fint(a);
    Mst[b].emplace_back(a, val);
    Mst[a].emplace_back(b, val);
}
inline void dfs(int v, int p, int d)
{
    Depth[v] = d;
    par[v][0] = p;
    for (auto w : Mst[v])
        if (w.first != p)
        {
            Cost[w.first][0] = w.second;
            dfs(w.first, v, d + 1);
        }
}
inline int query(int a, int b)
{
    if (Depth[a] > Depth[b])
        swap(a, b);
    int ans = 0;
    for (int d = L - 1; d >= 0; d--)
        if (Depth[b] - (1 << d) >= Depth[a])
        {
            ans = max(ans, Cost[b][d]);
            b = par[b][d];
        }

    assert(Depth[a] == Depth[b]);
    if (a == b)
        return ans;
    for (int d = L - 1; d >= 0; d--)
    {
        if (par[a][d] != par[b][d])
        {
            ans = max(ans, Cost[a][d]);
            a = par[a][d];
            ans = max(ans, Cost[b][d]);
            b = par[b][d];
        }
    }
    ans = max(ans, max(Cost[a][0], Cost[b][0]));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, a, b;
    cin >> n >> m >> q;
    for (int i = 0; i <= n; i++)
        R[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> E[i].start >> E[i].end;
        E[i].val = i + 1;
    }
    for (int i = 0; i < m; i++)
        onion(E[i].start, E[i].end, E[i].val);
    memset(Depth, -1, sizeof(Depth));
    memset(par, 0, sizeof(par));
    memset(Cost, 0, sizeof(Cost));

    for (int i = 1; i <= n; i++)
        if (Depth[i] == -1)
            dfs(i, i, 0);

    for (int k = 1; k < L; k++)
        for (int i = 1; i <= n; i++)
        {
            par[i][k] = par[par[i][k - 1]][k - 1];
            Cost[i][k] = max(Cost[i][k - 1], Cost[par[i][k - 1]][k - 1]);
        }
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        if (fint(R[a]) != fint(R[b]))
            cout << -1 << "\n";
        else
            cout << query(a, b) << "\n";
    }
    return 0;
}