#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct egde
{
    int node, id;
};
struct path
{
    int from, to, pathid;
};

class Solve
{
protected:
    int n, m, ilosc_spojnych = 0;
    vector<vector<egde>> Graf;
    vector<vector<int>> SCCGraf, ReversedSCCGraf;
    vector<path> sciezkal;
    vector<path> Edges;
    vector<bool> Vis;
    string ans;
    const char NotImportantEdge = '#';
    stack<int> Stos;

public:
    inline void findCycles(int v)
    {
        Vis[v] = 1;
        for (auto w : Graf[v])
        {
            sciezkal.push_back({v, w.node, w.id});
            if (!Vis[w.node])
            {
                findCycles(w.node);
            }
        }
    }

    inline void SCC_DFS(int v)
    {

        Vis[v] = 1;
        for (int w : SCCGraf[v])
            if (!Vis[w])
                SCC_DFS(w);

        Stos.push(v);
    }

    inline void count_dfs(int v)
    {
        Vis[v] = 1;

        for (int w : ReversedSCCGraf[v])
            if (!Vis[w])
                count_dfs(w);
    }
    inline void solve()
    {
        cin >> n >> m;
        Graf.resize(n + 1);
        Vis.resize(n + 1, 0);
        Edges.resize(m + 1);
        SCCGraf.resize(n + 1);
        ReversedSCCGraf.resize(n + 1);

        FOR(i, m, 0)
        {
            int a, b;
            cin >> a >> b;

            Graf[a].push_back({b, i});
            Graf[b].push_back({a, i});
            Edges[i] = {a, b, 0};
        }

        FOR(i, n + 1, 1)
        {
            if (Vis[i])
                continue;
            findCycles(i);
        }

        FOR(i, m, 0)
        ans.append("#");

        for (auto w : sciezkal)
        {
            if (ans[w.pathid] != NotImportantEdge)
                continue;
            if (Edges[w.pathid].from == w.from)
            {
                ans[w.pathid] = '>';
                SCCGraf[w.from].push_back(w.to);
                ReversedSCCGraf[w.to].push_back(w.from);
            }
            else
            {
                swap(w.from, w.to);
                ans[w.pathid] = '<';
                SCCGraf[w.to].push_back(w.from);
                ReversedSCCGraf[w.from].push_back(w.to);
            }
        }

        FOR(i, m, 0)
        if (ans[i] == NotImportantEdge)
        {
            ans[i] = '<';
            SCCGraf[Edges[i].to].push_back(Edges[i].from);
            ReversedSCCGraf[Edges[i].from].push_back(Edges[i].to);
        }

        FOR(i, n + 1, 1)
        Vis[i] = 0;

        FOR(i, n + 1, 1)
        {
            if (Vis[i])
                continue;

            SCC_DFS(i);
        }

        FOR(i, n + 1, 1)
        Vis[i] = 0;

        while (!Stos.empty())
        {
            int v = Stos.top();
            Stos.pop();
            if (Vis[v])
                continue;

            ilosc_spojnych++;
            count_dfs(v);
        }

        cout << ilosc_spojnych << "\n"
             << ans << '\n';
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