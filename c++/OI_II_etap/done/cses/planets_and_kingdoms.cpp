#include <bits/stdc++.h>
using namespace std;

/**
 * Description: Kosaraju's Algorithm, DFS twice to generate
 * strongly connected components in topological order. $a,b$
 * in same component if both $a\to b$ and $b\to a$ exist.
 * Time: O(N+M)
 * Source: Wikipedia
 * Verification: POI 8 peaceful commission
 */

struct SCC
{
    int N;
    vector<vector<int>> adj, radj;
    vector<int> todo, comp, comps;
    vector<bool> vis;
    void init(int _N)
    {
        N = _N;
        adj.resize(N), radj.resize(N), comp = vector<int>(N, -1), vis.resize(N);
    }
    void ae(int x, int y)
    {
        adj[x].push_back(y), radj[y].push_back(x);
    }
    void dfs(int x)
    {
        vis[x] = 1;
        for (int y : adj[x])
            if (!vis[y])
                dfs(y);
        todo.push_back(x);
    }
    void dfs2(int x, int v)
    {
        comp[x] = v;
        for (int y : radj[x])
            if (comp[y] == -1)
                dfs2(y, v);
    }
    void gen()
    { // fills allComp
        for (int i = 0; i < N; i++)
            if (!vis[i])
                dfs(i);
        reverse(begin(todo), end(todo));
        for (int x : todo)
            if (comp[x] == -1)
            {
                dfs2(x, x), comps.push_back(x);
            }
    }
};

int main()
{

    int n, m, a, b;
    cin >> n >> m;

    SCC graph;
    graph.init(n);
    while (m--)
    {
        cin >> a >> b;
        graph.ae(--a, --b);
    }
    graph.gen();

    int ID[200000]{};
    int ids = 0;
    for (int i = 0; i < n; i++)
    {
        if (!ID[graph.comp[i]])
        {
            ID[graph.comp[i]] = ++ids;
        }
    }
    cout << ids << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << ID[graph.comp[i]] << " \n"[i == n - 1];
    }
}