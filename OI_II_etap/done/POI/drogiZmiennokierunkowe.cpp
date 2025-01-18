#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, M;
    vector<vector<int>> SkierowanieParzyste;
    vector<vector<int>> SkierowanieNieParzyste;
    vector<vector<int>> SkierowanieNieParzysteSCC;
    vector<vector<int>> SkierowanieParzysteSCC;

    vector<bool> Wyrzucone;
    vector<int> STONieParzyste;
    vector<int> Spojna;
    vector<vector<int>> SCC;
    vector<bool> Vis;

    set<int> SonsiedziSpojnych;
    stack<int> stackSCC;
    set<int> Ans;
    int idSpojnej = 0;

    queue<int> KolejkaTopoSort;
    vector<int> Toposort;

public:
    inline void read_data()
    {
        cin >> N >> M;

        SkierowanieParzyste.resize(N + 1);
        SkierowanieNieParzyste.resize(N + 1);
        SkierowanieNieParzysteSCC.resize(N + 1);
        SkierowanieParzysteSCC.resize(N + 1);
        Spojna.resize(N + 1);
        Vis.resize(N + 1);
        SCC.resize(N + 1);
        Wyrzucone.resize(N + 1);

        FOR(i, M, 0)
        {
            int a, b;
            cin >> a >> b;
            SkierowanieNieParzyste[a].push_back(b);
            SkierowanieParzyste[b].push_back(a);
        }
    }

    inline void set_vis()
    {
        FOR(i, N + 1, 0)
        Vis[i] = 0;
    }

    inline void createSCC_graph()
    {
        STONieParzyste.resize(N + 1);

        FOR(i, idSpojnej + 1, 1)
        {
            SonsiedziSpojnych.clear();
            for (int v : SCC[i])
                for (int w : SkierowanieNieParzyste[v])
                    SonsiedziSpojnych.insert(Spojna[w]);

            for (int id : SonsiedziSpojnych)
            {
                if (id == i)
                    continue;

                SkierowanieNieParzysteSCC[i].push_back(id);
                SkierowanieParzysteSCC[id].push_back(i);
                STONieParzyste[id]++;
            }
        }
    }

    inline void firstSccdfs(int v)
    {
        Vis[v] = 1;

        for (int w : SkierowanieNieParzyste[v])
            if (!Vis[w])
                firstSccdfs(w);

        stackSCC.push(v);
    }

    inline void secondSCC_dfs(int v)
    {
        Vis[v] = 1;
        Spojna[v] = idSpojnej;
        SCC[idSpojnej].push_back(v);

        for (int w : SkierowanieParzyste[v])
            if (!Vis[w])
                secondSCC_dfs(w);
    }

    inline void get_scc()
    {

        FOR(i, N + 1, 1)
        if (!Vis[i])
            firstSccdfs(i);

        set_vis();

        while (!stackSCC.empty())
        {
            int v = stackSCC.top();
            stackSCC.pop();
            if (!Vis[v])
            {
                idSpojnej++;
                secondSCC_dfs(v);
            }
        }
        createSCC_graph();
    }

    inline void get_start_points(queue<int> &Kolejka, vector<int> &STO)
    {
        FOR(i, idSpojnej + 1, 1)
        if (STO[i] == 0)
            Kolejka.push(i);
    }

    inline void sortuj_topo(vector<vector<int>> &Graf, vector<int> &STO)
    {
        while (!KolejkaTopoSort.empty())
        {
            int v = KolejkaTopoSort.front();

            KolejkaTopoSort.pop();
            Toposort.push_back(v);

            for (int w : Graf[v])
            {
                STO[w]--;
                if (STO[w] == 0)
                    KolejkaTopoSort.push(w);
            }
        }
    }

    inline void solve()
    {
        read_data();

        // transform graf to SCC graf
        get_scc();

        // sprawdz ile jest pól startowych, jezeli ani parzysty ani nie parzysty nie ma 1 pola to ans = 0
        get_start_points(KolejkaTopoSort, STONieParzyste);
        sortuj_topo(SkierowanieNieParzysteSCC, STONieParzyste);

        vector<int> Czy(N + 1, 0);
        int licznik = 0;

        for (int i = Toposort.size() - 1; i >= 0; i--)
        {
            int v = Toposort[i];

            for (int w : SkierowanieNieParzysteSCC[v])
                if (Czy[w] == 1)
                {
                    licznik--;
                    Czy[w] = 0;
                }

            if (licznik > 0)
                Wyrzucone[v] = 1;

            Czy[v] = 1;
            licznik++;
        }

        FOR(i, N + 1, 0)
        Czy[i] = 0;

        licznik = 0;

        FOR(i, Toposort.size(), 0)
        {
            int v = Toposort[i];

            for (int w : SkierowanieParzysteSCC[v])
                if (Czy[w] == 1)
                {
                    licznik--;
                    Czy[w] = 0;
                }

            if (licznik > 0)
                Wyrzucone[v] = 1;

            Czy[v] = 1;
            licznik++;
        }

        FOR(i, idSpojnej + 1, 1)
        if (!Wyrzucone[i])
            for (int w : SCC[i])
                Ans.insert(w);

        cout << Ans.size() << '\n';

        for (int w : Ans)
            cout << w << ' ';

        cout << '\n';
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