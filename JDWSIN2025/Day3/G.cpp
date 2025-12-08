#include <bits/stdc++.h>
using namespace std;

struct elementsToColor
{
    int key;
    set<int> elements;
};
queue<elementsToColor> toColor;
int n, m;

inline void dfsTreeAlgo(int v, const vector<vector<int>> &Graph, vector<bool> &Vis, vector<vector<int>> &IleWGore, vector<set<int>> &dfsTree, vector<int> &Parent)
{
    Vis[v] = true;

    for (int w : Graph[v])
    {
        if (Vis[w])
            IleWGore[v].push_back(w);

        if (!Vis[w])
        {
            Parent[w] = v;
            dfsTree[v].insert(w);
            dfsTreeAlgo(w, Graph, Vis, IleWGore, dfsTree, Parent);
        }
    }
}
inline void ansDfs(int v, vector<set<int>> &dfsTree, vector<int> &Coloring, vector<vector<int>> &ILeWGore, set<int> &Vis, int &currentColor)
{
    Vis.insert(v);
    int sto = 0;
    // dfs to leaves
    for (int w : dfsTree[v])
        if (Coloring[w] == 0)
            ansDfs(w, dfsTree, Coloring, ILeWGore, Vis, currentColor);

    for (int w : dfsTree[v])
        if (Coloring[w] == 0)
            sto++;

    if (sto > 0)
    {

        if ((sto & 1) == 1)
        {
            currentColor++;
            for (int w : dfsTree[v])
                if (Coloring[w] == 0)
                    Coloring[w] = currentColor;

            Coloring[v] = currentColor;
        }
        else
        {
            pair<int, int> jmp = {0, 0};

            for (int w : dfsTree[v])
                if (Coloring[w] == 0)
                    for (int u : ILeWGore[w])
                        if (Vis.count(u) && Coloring[u] == 0)
                            jmp = {u, w};

            if (jmp.first != 0)
            {
                dfsTree[jmp.first].insert(jmp.second);
                dfsTree[v].erase(jmp.second);

                currentColor++;
                for (int w : dfsTree[v])
                    if (Coloring[w] == 0)
                        Coloring[w] = currentColor;

                Coloring[v] = currentColor;
            }

            else
            {
                elementsToColor el;
                el.key = v;
                for (int w : dfsTree[v])
                    if (Coloring[w] == 0)
                        el.elements.insert(w);

                toColor.push(el);
            }
        }
    }

    Vis.erase(v);
}

void solve()
{

    cin >> n >> m;
    vector<vector<int>> Graph(n + 10);
    vector<bool> Vis(n + 10, 0);
    vector<set<int>> dfsTree(n + 10);
    vector<int> Coloring(n + 10), Depth(n + 10);
    vector<vector<int>> IleWGore(n + 10);
    vector<int> Parent(n + 10);

    set<int> VisSet;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a].emplace_back(b);
        Graph[b].emplace_back(a);
    }
    if ((n & 1) == 1)
    {
        cout << -1 << "\n";
        return;
    }

    // dfs tree

    dfsTreeAlgo(1, Graph, Vis, IleWGore, dfsTree, Parent);
    int currentColor = 0;

    ansDfs(1, dfsTree, Coloring, IleWGore, VisSet, currentColor);

    while (!toColor.empty())
    {
        auto el = toColor.front();
        toColor.pop();

        int color = Coloring[el.key];
        if (color == 0)
        {
            toColor.push(el);
            continue;
        }

        for (int w : el.elements)
            Coloring[w] = color;
    }

    for (int i = 1; i <= n; i++)
        cout << Coloring[i] << " ";

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}