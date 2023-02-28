#include <bits/stdc++.h>

using namespace std;
constexpr int M = 5010;
vector<pair<int, int>> Tree[M];
int k, res;
void dfs(int v, int p)
{
    for (auto w : Tree[v])
        if (w.first != p && w.second >= k)
        {
            res++;
            dfs(w.first, v);
        }
}
int main()
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b, w;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> w;
        Tree[a].push_back({b, w});
        Tree[b].push_back({a, w});
    }
    for (int i = 0; i < q; i++)
    {
        cin >> k >> a;
        res = 0;
        dfs(a, a);
        cout << res << "\n";
    }
    return 0;
}