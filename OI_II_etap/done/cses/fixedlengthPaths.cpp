#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
constexpr int M = 2e5 + 10;
int k;
vector<int> Tree[M];
bool is_off[M];
int Sajz[M], Parent[M];
ull res;
unordered_map<int, int> mapa;
void dfs(int v, int p)
{
    Sajz[v] = 1;
    Parent[v] = p;
    for (int w : Tree[v])
        if (w != p && !is_off[w])
        {
            dfs(w, v);
            Sajz[v] += Sajz[w];
        }
}
void result_dfs(int v, int p, int d)
{
    if (d > k)
        return;
    res += mapa[k - d];
    for (int w : Tree[v])
        if (w != p && !is_off[w])
            result_dfs(w, v, d + 1);
}
void update_dfs(int v, int p, int d)
{
    if (d > k)
        return;
    mapa[d]++;
    for (int w : Tree[v])
        if (w != p && !is_off[w])
            update_dfs(w, v, d + 1);
}
int find_centroid(int v, int tree_size)
{
    for (int w : Tree[v])
    {
        if (is_off[w])
            continue;
        if (w == Parent[v] && tree_size - Sajz[v] > ((tree_size + 1) / 2))
            return find_centroid(w, tree_size);
        else if (w != Parent[v] && Sajz[w] > ((tree_size + 1) / 2))
            return find_centroid(w, tree_size);
    }
    return v;
}
void centroid_dec(int V, int tree_size)
{
    if (tree_size < k)
        return;
    dfs(V, 0);
    int centr = find_centroid(V, tree_size);
    mapa[0] = 1;
    for (int w : Tree[centr])
    {
        if (is_off[w])
            continue;
        result_dfs(w, centr, 1);
        update_dfs(w, centr, 1);
    }
    mapa.clear();
    is_off[centr] = 1;
    for (int w : Tree[centr])
        if (!is_off[w])
        {
            int new_size = (Sajz[w] < Sajz[centr] ? Sajz[w] : tree_size - Sajz[centr]);
            centroid_dec(w, new_size);
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    centroid_dec(1, n);
    cout << res;
    return 0;
}