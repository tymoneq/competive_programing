#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    struct edge
    {
        int from, weight;
    };

    int N, K;
    ll res = 0;
    vector<vector<edge>> Drzewo;
    vector<int> Ile_zapalonych_w_centroidzie;
    vector<ll> Suma_dystansow;
    vector<int> Centroid_nad;
    vector<bool> Off;
    vector<unordered_map<int, ll>> Dystanse_od_centroidu;
    vector<int> Parent;
    vector<int> Sajz;
    vector<unordered_map<int, ll>> SumaSynow;

public:
    inline void
    read_data()
    {
        cin >> N >> K;

        Drzewo.resize(N + 1);
        Centroid_nad.resize(N + 1);
        Off.resize(N + 1);
        Parent.resize(N + 1);
        Sajz.resize(N + 1);
        Dystanse_od_centroidu.resize(N + 1);

        FOR(i, N, 1)
        {
            int from, to, cost;

            cin >> from >> to >> cost;

            Drzewo[from].push_back({to, cost});
            Drzewo[to].push_back({from, cost});
        }
    }

    inline void size_dfs(int v, int p)
    {
        Sajz[v] = 1;
        Parent[v] = p;

        for (auto w : Drzewo[v])
            if (w.from != p && !Off[w.from])
            {
                size_dfs(w.from, v);
                Sajz[v] += Sajz[w.from];
            }
    }

    inline int find_centroid(int v, int tree_sajz)
    {

        for (auto w : Drzewo[v])
        {
            if (Off[w.from])
                continue;

            if (Parent[v] == w.from && tree_sajz - Sajz[v] > ((tree_sajz + 1) / 2))
                return find_centroid(w.from, tree_sajz);

            if (Parent[v] != w.from && Sajz[w.from] > ((tree_sajz + 1) / 2))
                return find_centroid(w.from, tree_sajz);
        }

        return v;
    }

    inline void dist_dfs(int v, int p, ll dist, const int &centr)
    {
        Dystanse_od_centroidu[centr][v] = dist;
        for (auto w : Drzewo[v])
            if (w.from != p && !Off[w.from])
                dist_dfs(w.from, v, dist + w.weight, centr);
    }

    inline void centroid_decomposition(int v, int tree_sajz, int centroid_nad)
    {

        size_dfs(v, v);

        int centr = find_centroid(v, tree_sajz);

        dist_dfs(centr, centr, 0, centr);

        Off[centr] = true;
        Centroid_nad[centr] = centroid_nad;

        for (auto w : Drzewo[centr])
        {
            if (Off[w.from])
                continue;

            if (Parent[centr] == w.from)
            {
                int new_tree_sajz = tree_sajz - Sajz[centr];
                centroid_decomposition(w.from, new_tree_sajz, centr);
            }
            else
            {
                int new_tree_sajz = Sajz[w.from];
                centroid_decomposition(w.from, new_tree_sajz, centr);
            }
        }
    }

    inline void dodaj(int v, int zamek)
    {
        Ile_zapalonych_w_centroidzie[v]++;
        Suma_dystansow[v] += Dystanse_od_centroidu[v][zamek];

        if (Centroid_nad[v] != 0)
        {
            SumaSynow[Centroid_nad[v]][v] += Dystanse_od_centroidu[Centroid_nad[v]][zamek];
            dodaj(Centroid_nad[v], zamek);
        }
    }

    inline ll zapytaj(int v, const int zamek)
    {
        ll sum = 0;
        sum += Suma_dystansow[v];

        while (Centroid_nad[v] != 0)
        {
            int parent = Centroid_nad[v];

            sum += Dystanse_od_centroidu[parent][zamek] * (Ile_zapalonych_w_centroidzie[parent] - Ile_zapalonych_w_centroidzie[v]);
            sum += Suma_dystansow[parent] - SumaSynow[parent][v];

            v = parent;
        }

        return sum;
    }

    inline void solve()
    {

        read_data();
        centroid_decomposition(1, N, 0);

        Ile_zapalonych_w_centroidzie.resize(N + 1);
        Suma_dystansow.resize(N + 1);
        SumaSynow.resize(N + 1);

        dodaj(1, 1);

        FOR(i, K, 0)
        {
            int nowy_zamek;
            cin >> nowy_zamek;

            res += zapytaj(nowy_zamek, nowy_zamek);
            dodaj(nowy_zamek, nowy_zamek);

            cout << res * 2 << '\n';
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