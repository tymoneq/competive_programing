#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

constexpr int N = 1e5 + 10, base = 1 << 18;

int Sajz[N], Pre[N], Parent[N], Post[N], nxt = 0, Path_end[N], depth[N];
vector<int> adj[N];
int Tree[base << 1], Tree_lazy[base << 1];

inline void size_dfs(int v, int p)
{
    Sajz[v] = 1;
    depth[v] = depth[p] + 1;
    Parent[v] = p;
    for (int w : adj[v])
        if (w != p)
        {
            size_dfs(w, v);
            Sajz[v] += Sajz[w];
        }
}

inline void make_hld(int v, int p)
{
    Pre[v] = nxt;

    int heavy = 0;
    for (int w : adj[v])
        if (w != p && Sajz[w] > Sajz[heavy])
            heavy = w;

    if (heavy)
    {
        nxt++;
        Path_end[heavy] = Path_end[v];
        make_hld(heavy, v);
    }
    for (int w : adj[v])
        if (w != p && w != heavy)
        {
            nxt++;
            Path_end[w] = w;
            make_hld(w, v);
        }
    Post[v] = nxt;
}

void push(int v, int l, int r)
{
    Tree[l] += Tree_lazy[v];
    Tree[r] += Tree_lazy[v];
    Tree_lazy[l] += Tree_lazy[v];
    Tree_lazy[r] += Tree_lazy[v];

    Tree_lazy[v] = 0;
}

inline void add(int v, int a, int b, int lo, int hi, int x)
{
    if (hi < a || lo > b)
        return;

    if (lo <= a && b <= hi)
    {
        Tree[v] += x;
        Tree_lazy[v] += x;
    }
    else
    {
        int l = 2 * v, r = v * 2 + 1, mid = (a + b) / 2;
        push(v, l, r);

        add(l, a, mid, lo, hi, x);
        add(r, mid + 1, b, lo, hi, x);

        Tree[v] = max(Tree[l], Tree[r]);
    }
}

inline int querry(int v, int a, int b, int lo, int hi)
{
    if (hi < a || lo > b)
        return numeric_limits<int>::min();

    if (lo <= a && b <= hi)
        return Tree[v];

    else
    {
        int l = 2 * v, r = v * 2 + 1, mid = (a + b) / 2;
        push(v, l, r);
        return max(querry(l, a, mid, lo, hi), querry(r, mid + 1, b, lo, hi));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    int n, q, a, b;
    string type;

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = base; i < (base << 1); i++)
        Tree[i] = numeric_limits<int>::min();
    for (int i = base - 1; i >= 0; i--)
        Tree[i] = numeric_limits<int>::min();

    Path_end[1] = 1;
    size_dfs(1, 0);
    make_hld(1, 0);

    cin >> q;

    while (q--)
    {
        cin >> type >> a >> b;
        if (type == "add")
            add(1, 0, base - 1, Pre[a], Post[a], b);

        else
        {
            int res = numeric_limits<int>::min();

            while (Path_end[a] != Path_end[b])
            {
                if (depth[Path_end[a]] < depth[Path_end[b]])
                    swap(a, b);

                res = max(res, querry(1, 0, base - 1, Pre[Path_end[a]], Pre[a]));

                a = Parent[Path_end[a]];
            }
            if (Pre[a] < Pre[b])
                swap(a, b);

            res = max(res, querry(1, 0, base - 1, Pre[b], Pre[a]));
            cout << res << "\n";
        }
    }

    return 0;
}