#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
vector<int> Graph[M];
int res, k, K, tmp, tajm;
bool Vis[M];
int Cycle[M];
int Index[M];
vector<int> Q;
inline void Find_cycle(int v)
{
    if (Vis[v])
    {
        tajm = tmp - Index[v];
        for (int i = Index[v]; i > Index[v] - 1; i--)
            Cycle[Q[i]] = tajm;

        for (int h : Q)
            Vis[h] = 0;
        Q.clear();
        return;
    }
    Vis[v] = 1;
    Index[v] = tmp;
    tmp++;
    Q.push_back(v);
    for (int w : Graph[v])
        Find_cycle(w);
}
inline void dfs(int v)
{
    if (tajm != numeric_limits<int>::max())
        tajm--;
    if (Cycle[v] != 0 && tajm == numeric_limits<int>::max())
    {
        tajm = (k - K) % Cycle[v];
    }
    if (tajm == 0)
    {
        res = v;
        return;
    }
    if (K == k)
    {
        res = v;
        return;
    }
    K++;
    for (int w : Graph[v])
        dfs(w);
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, x;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        Graph[i].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (Vis[i])
            continue;
        tmp = 0;
        Find_cycle(i);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x >> k;
        K = 0;
        tajm = numeric_limits<int>::max();
        dfs(x);
        cout << res << "\n";
    }
    return 0;
}