#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)
typedef long long ll;

class Solve
{
protected:
    struct PunktStartowy
    {
        int PointX, PointY;
    };
    struct edge
    {
        int cost;
        PunktStartowy from, to;
    };

    int N, M, T;
    ll res = 0;
    vector<edge> Krawedzie;
    vector<vector<int>> Grid;
    vector<int> Reprezentant;
    vector<int> Sajz;
    vector<vector<int>> Specjalne;

public:
    inline int get_id(PunktStartowy Punkt)
    {
        return Punkt.PointX * M + Punkt.PointY;
    }
    inline void read_data()
    {
        cin >> N >> M >> T;

        Grid.resize(N);
        Reprezentant.resize(N * M);
        Sajz.resize(N * M);
        Specjalne.resize(N * M);

        FOR(i, N, 0)
        {
            Grid[i].resize(M);

            FOR(j, M, 0)
            cin >> Grid[i][j];
        }

        FOR(i, N, 0)
        FOR(j, M, 0)
        {
            int type;
            cin >> type;
            if (type == 1)
            {

                int id = get_id({i, j});
                Specjalne[id].push_back(id);
            }
        }
        FOR(i, N * M, 0)
        {
            Reprezentant[i] = i;
            Sajz[i] = 1;
        }
    }
    inline int calcCost(int val1, int val2)
    {
        return abs(val1 - val2);
    }
    inline void createEdges()
    {

        FOR(i, N, 0)
        FOR(j, M, 0)
        {
            if (j + 1 < M)
            {
                int cost = calcCost(Grid[i][j], Grid[i][j + 1]);
                Krawedzie.push_back({cost, {i, j}, {i, j + 1}});
            }
            if (i + 1 < N)
            {
                int cost = calcCost(Grid[i][j], Grid[i + 1][j]);
                Krawedzie.push_back({cost, {i, j}, {i + 1, j}});
            }
        }
        sort(Krawedzie.begin(), Krawedzie.end(), [this](const edge &lhs, const edge &rhs)
             { return lhs.cost < rhs.cost; });
    }

    inline int fint(int v) { return Reprezentant[v] == v ? v : fint(Reprezentant[v]); }

    inline void onion(int from, int to, int cost)
    {
        from = fint(from);
        to = fint(to);

        if (from == to)
            return;

        if (Sajz[from] < Sajz[to])
            swap(from, to);

        // skopiowanie specjalnych wierzchołków

        for (int specialny : Specjalne[to])
            Specjalne[from].push_back(specialny);

        Sajz[from] += Sajz[to];
        Sajz[to] = 0;
        Reprezentant[to] = from;

        if (Sajz[from] >= T)
        {
            res += Specjalne[from].size() * cost;
            Specjalne[from].clear();
        }

    }

    inline void solve()
    {
        read_data();

        // create graf
        createEdges();

        for (edge krawedz : Krawedzie)
        {

            // dodaj do grafu
            int id_from = get_id(krawedz.from);
            int id_to = get_id(krawedz.to);

            onion(id_from, id_to, krawedz.cost);
        }

        cout << res << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);

    Solve solution;
    solution.solve();
    return 0;
}