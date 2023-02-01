#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e6 + 10;
vector<int> Graph[M];
int Pre[M], Post[M], jmp[M][17], Cost[M][17], Depth[M];

int timer, L = 17;
void dfs(int v, int p)
{
    timer++;
    Pre[v] = timer;
    Depth[v] = Depth[p] + 1;
    jmp[v][0] = p;
    for (int i = 1; i <= L; i++)
        jmp[v][i] = jmp[jmp[v][i - 1]][i - 1]; // jmp[v][k] = jmp[jmp[v][k-1]][k-1];
    for (int w : Graph[v])
        if (w != p)
            dfs(w, v);
    Post[v] = ++timer;
}
inline bool is_ancestor(int u, int v) { return Pre[u] <= Pre[v] && Post[u] >= Post[v]; }
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = L; i >= 0; i--)
        if (jmp[u][i] != -1 && !is_ancestor(jmp[u][i], v))
            u = jmp[u][i];
    return jmp[u][0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= L; i++)
        jmp[1][i] = -1;
    return 0;
}