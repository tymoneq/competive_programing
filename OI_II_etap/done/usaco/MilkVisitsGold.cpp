#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct Zapytanie
{
    int to, id, type;
};

class Solve
{
protected:
    const int MAXLOG = 17;

    vector<vector<Zapytanie>> Zapytania;
    vector<vector<int>> drzewo;
    vector<stack<int>> OstatnieWystapienie;
    vector<vector<int>> jmp;
    vector<int> Type;
    vector<int> Wynik;
    vector<int> PreOrder, PostOrder;
    int n, m;

public:
    inline void lca_dfs(int v, int p, int &timer)
    {
        PreOrder[v] = timer;
        timer++;
        jmp[v][0] = p;

        FOR(i, MAXLOG, 1)
        jmp[v][i] = jmp[jmp[v][i - 1]][i - 1];

        for (int w : drzewo[v])
            if (w != p)
                lca_dfs(w, v, timer);

        PostOrder[v] = timer;
        timer++;
    }

    inline bool isAncestor(int v, int u)
    {
        return PreOrder[v] <= PreOrder[u] && PostOrder[v] >= PostOrder[u];
    }

    inline int find_lca(int v, int u)
    {
        if (isAncestor(v, u))
            return v;
        if (isAncestor(u, v))
            return u;

        for (int i = MAXLOG - 1; i >= 0; i--)
            if (jmp[u][i] != 0 && !isAncestor(jmp[u][i], v))
                u = jmp[u][i];

        return jmp[u][0];
    }
    inline void calc_dfs(int v, int p)
    {
        OstatnieWystapienie[Type[v]].push(v);

        // calc res for vertex

        for (auto zapytanie : Zapytania[v])
        {
            int ans = 0;

            // find lca potem sprawdz czy ostatnie wystąpienie typu leży w niżej niż lca

            int lca = find_lca(v, zapytanie.to);
            if (OstatnieWystapienie[zapytanie.type].empty())
                continue;

            int lastOccurance = OstatnieWystapienie[zapytanie.type].top();

            if (isAncestor(lca, lastOccurance))
                ans = 1;

            Wynik[zapytanie.id] |= ans;
        }

        // rekurencja
        for (int w : drzewo[v])
            if (w != p)
                calc_dfs(w, v);

        OstatnieWystapienie[Type[v]].pop();
    }

    inline void solve()
    {
        cin >> n >> m;
        Type.resize(n + 1);
        drzewo.resize(n + 1);
        Zapytania.resize(n + 1);
        Wynik.resize(m);
        OstatnieWystapienie.resize(n + 1);
        PreOrder.resize(n + 1);
        PostOrder.resize(n + 1);
        jmp.resize(n + 1);

        FOR(i, n + 1, 1)
        cin >> Type[i];

        FOR(i, n + 1, 0)
        jmp[i].resize(MAXLOG);

        FOR(i, n, 1)
        {
            int a, b;
            cin >> a >> b;
            drzewo[a].push_back(b);
            drzewo[b].push_back(a);
        }

        FOR(i, m, 0)
        {
            int from, to, type;
            cin >> from >> to >> type;
            Zapytania[from].push_back({to, i, type});
            Zapytania[to].push_back({from, i, type});
        }

        // policzenie lca
        int timer = 0;
        lca_dfs(1, 0, timer);
        calc_dfs(1, 1);

        FOR(i, m, 0)
        cout << Wynik[i];

        cout << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}