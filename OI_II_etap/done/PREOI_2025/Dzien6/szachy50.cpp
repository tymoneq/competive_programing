#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, M;
    vector<int> Ans;

    vector<vector<int>> ReverseGraph;
    vector<vector<int>> Graph;
    vector<vector<int>> SCC;
    vector<bool> Vis;
    vector<vector<int>> SCC_graph;

    vector<vector<int>> WarstwyTopo;
    queue<int> KolejkaTopoSort;
    stack<int> S;
    int spojna = -1;
    vector<int> Sto;
    vector<int> Id_spojnej;

public:
    inline void
    read_data()
    {
        cin >> N >> M;

        Ans.resize(N + 1, 1);
        Sto.resize(N + 1);
        Id_spojnej.resize(N + 1);
        ReverseGraph.resize(N + 1);
        Graph.resize(N + 1);
        Vis.resize(N + 1);

        WarstwyTopo.resize(N + 1);

        FOR(i, M, 0)
        {
            int from, to;
            cin >> from >> to;

            Graph[from].push_back(to);
            ReverseGraph[to].push_back(from);
        }
    }

    inline void first_dfs(int v)
    {
        Vis[v] = true;

        for (int w : Graph[v])
            if (!Vis[w])
                first_dfs(w);

        S.push(v);
    }

    inline void second_dfs(int v)
    {
        Vis[v] = true;
        SCC[spojna].push_back(v);
        Id_spojnej[v] = spojna;

        for (int w : ReverseGraph[v])
            if (!Vis[w])
                second_dfs(w);
    }

    inline void scc()
    {

        FOR(i, N + 1, 1)
        {
            if (Vis[i])
                continue;

            first_dfs(i);
        }

        FOR(i, N + 1, 1)
        Vis[i] = false;

        while (!S.empty())
        {
            int v = S.top();
            S.pop();

            if (Vis[v])
                continue;
            else
            {
                spojna++;
                SCC.push_back({});
                second_dfs(v);
            }
        }

        SCC_graph.resize(spojna + 1);

        FOR(i, spojna + 1, 0)
        {
            set<int> Somsiad;

            for (int w : SCC[i])
                for (int som : Graph[w])
                    if (Id_spojnej[som] != i)
                        Somsiad.insert(Id_spojnej[som]);

            for (int w : Somsiad)
            {
                SCC_graph[i].push_back(w);
                Sto[w]++;
            }
        }
    }

    inline void topoSort()
    {
        vector<int> Id_warstwy(spojna + 1);

        FOR(i, spojna + 1, 0)
        if (Sto[i] == 0)
        {
            KolejkaTopoSort.push(i);
            WarstwyTopo[0].push_back(i);
        }

        while (!KolejkaTopoSort.empty())
        {
            int v = KolejkaTopoSort.front();
            KolejkaTopoSort.pop();

            for (int w : SCC_graph[v])
            {
                Id_warstwy[w] = max(Id_warstwy[w], Id_warstwy[v]);
                Sto[w]--;

                if (Sto[w] == 0)
                {
                    KolejkaTopoSort.push(w);
                    Id_warstwy[w]++;
                    WarstwyTopo[Id_warstwy[w]].push_back(w);
                }
            }
        }

        FOR(i, N + 1, 0)
        {
            if (WarstwyTopo[i].size() == 0)
                continue;

            if (WarstwyTopo[i].size() > 1)
                for (int spojna : WarstwyTopo[i])
                    for (int v : SCC[spojna])
                        Ans[v] = -1;

            if (WarstwyTopo[i].size() == 1 && SCC[WarstwyTopo[i][0]].size() > 1)
            {
                for (int spojna : WarstwyTopo[i])
                    for (int v : SCC[spojna])
                        Ans[v] = -1;
            }
        }
    }

    inline void solve()
    {
        read_data();
        scc();

        topoSort();

        FOR(i, N + 1, 1)
        cout << Ans[i] << " ";

        cout << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve s;
    s.solve();

    return 0;
}