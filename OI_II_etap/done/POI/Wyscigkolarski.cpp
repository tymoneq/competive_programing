#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    const int MAXLOG = 20;
    int N, M, Q;
    vector<vector<int>> Graf;
    vector<vector<int>> drzewoDFS;
    vector<vector<int>> QueryNaDrzewieDFS;
    vector<vector<int>> LCA;
    vector<int> Ile;
    vector<int> Depth;
    vector<int> sumaZapalonych;
    vector<bool> Vis;
    vector<int> Pre, Post;

public:
    inline void read_data()
    {
        cin >> N >> M;

        Graf.resize(N + 1);
        drzewoDFS.resize(N + 1);
        QueryNaDrzewieDFS.resize(N + 1);
        LCA.resize(N + 1);
        Ile.resize(N + 1);
        sumaZapalonych.resize(N + 1);
        Vis.resize(N + 1);
        Depth.resize(N + 1);
        Pre.resize(N + 1);
        Post.resize(N + 1);

        FOR(i, M, 0)
        {
            int a, b;
            cin >> a >> b;
            Graf[a].push_back(b);
        }

        FOR(i, N + 1, 0)
        LCA[i].resize(MAXLOG, 0);
    }

    inline void dfs(int v)
    {
        Vis[v] = 1;
        for (int w : Graf[v])
        {
            if (Vis[w])
                QueryNaDrzewieDFS[v].push_back(w);

            if (!Vis[w])
            {
                drzewoDFS[v].push_back(w);
                dfs(w);
            }
        }
    }

    inline void lca_dfs(int v, int p, int &timer)
    {
        Depth[v] = Depth[p] + 1;
        Pre[v] = timer;
        timer++;
        LCA[v][0] = p;

        FOR(jump, MAXLOG, 1)
        LCA[v][jump] = LCA[LCA[v][jump - 1]][jump - 1];

        for (int w : drzewoDFS[v])
            if (w != p)
                lca_dfs(w, v, timer);

        Post[v] = timer;
        timer++;
    }

    inline bool is_ancestor(int u, int v)
    {
        return Pre[u] <= Pre[v] && Post[u] >= Post[v];
    }

    inline int get_lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;

        for (int jmp = MAXLOG - 1; jmp >= 0; jmp--)
            if (LCA[u][jmp] != 0 && !is_ancestor(LCA[u][jmp], v))
                u = LCA[u][jmp];

        return LCA[u][0];
    }

    inline void tworzenieStruktury_dfs(int v, int p)
    {
        for (int w : QueryNaDrzewieDFS[v])
        {
            // znajdz lca, dodaj +1 na kazdym v i u i odejmij -2 od ojca lca
            int lca = get_lca(w, v);

            sumaZapalonych[v]++;
            sumaZapalonych[w]++;

            sumaZapalonych[LCA[lca][0]] -= 2;
        }

        for (int w : drzewoDFS[v])
            if (w != p)
                tworzenieStruktury_dfs(w, v);
    }

    inline void zliczenieSum_dfs(int v, int p)
    {

        for (int w : drzewoDFS[v])
            if (w != p)
            {
                zliczenieSum_dfs(w, v);
                sumaZapalonych[v] += sumaZapalonych[w];
            }
    }

    inline void policzIleSpecjialnych_dfs(int v, int p, int &ile)
    {
        Ile[v] = Ile[p] + (sumaZapalonych[v] > 0 ? 1 : 0);

        ile += (sumaZapalonych[v] > 0 ? 1 : 0);

        for (int w : drzewoDFS[v])
            policzIleSpecjialnych_dfs(w, v, ile);
    }

    inline void solve()
    {
        read_data();

        int timer = 0;

        dfs(1);
        lca_dfs(1, 0, timer);
        tworzenieStruktury_dfs(1, 0);
        zliczenieSum_dfs(1, 0);

        int ile = 0;
        policzIleSpecjialnych_dfs(1, 0, ile);

        cout << ile << '\n';

        cin >> Q;

        while (Q--)
        {
            int a, b;
            cin >> a >> b;
            int lca = get_lca(a, b);

            int sumaDepth = Depth[a] + Depth[b] - 2 * Depth[lca] + 1;
            int ileZapalonych = Ile[a] + Ile[b] - 2 * Ile[lca] + (sumaZapalonych[lca] > 0 ? 1 : 0);

            int wynik = sumaDepth - ileZapalonych + ile;

            cout << wynik << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve solution;
    solution.solve();

    return 0;
}