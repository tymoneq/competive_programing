#include <bits/stdc++.h>
using namespace std;
constexpr int M = 1e5 + 7;
vector<pair<int, int>> G[M];
bool is_off[M];
int Sajz[M], parent[M];
unsigned long long res;
unordered_map<long long, int> mapa;

void result_dfs(int v, int p, long long ksor)
{
    res += mapa[ksor];
    for (auto w : G[v])
        if (!is_off[w.first] && w.first != p)
            result_dfs(w.first, v, ksor ^ w.second);
}
void uptade_dfs(int v, int p, long long ksor)
{
    mapa[ksor]++;
    for (auto w : G[v])
        if (!is_off[w.first] && w.first != p)
            uptade_dfs(w.first, v, ksor ^ w.second);
}
void dfs(int v, int p)
{
    Sajz[v] = 1;
    parent[v] = p;
    for (auto w : G[v])
        if (w.first != p && !is_off[w.first])
        {
            dfs(w.first, v);
            Sajz[v] += Sajz[w.first];
        }
}
int find_centroid(int v, int tree_sajz)
{
    for (auto w : G[v])
    {
        if (is_off[w.first])
            continue;
        if (w.first == parent[v] && tree_sajz - Sajz[v] > ((tree_sajz + 1) / 2))
            return find_centroid(parent[v], tree_sajz);
        else if (w.first != parent[v] && Sajz[w.first] > (((tree_sajz + 1) / 2)))
            return find_centroid(w.first, tree_sajz);
    }
    return v;
}
void centroid_decomposition(int v, int tree_sajz)
{
    if (tree_sajz == 1)
        return;
    dfs(v, 0);
    int centr = find_centroid(v, tree_sajz);
    mapa[0] = 1;
    for (auto w : G[centr])
        if (!is_off[w.first])
        {
            result_dfs(w.first, centr, w.second);
            uptade_dfs(w.first, centr, w.second);
        }
    mapa.clear();
    is_off[centr] = 1;
    for (auto w : G[centr])
        if (!is_off[w.first])
        {
            int new_size = (Sajz[w.first] < Sajz[centr] ? Sajz[w.first] : tree_sajz - Sajz[centr]);
            centroid_decomposition(w.first, new_size);
        }
}
int main()
{
    int n, a, b, c;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    centroid_decomposition(1, n);
    cout << res << "\n";
    return 0;
}