#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;
class Solve
{
protected:
    static const ll INF = 1e18 + 5;
    int N, M;
    struct edge
    {
        int from, to, cost;
    };

    vector<vector<edge>> Miasto;
    vector<edge> Kraw;
    vector<int> Rep;
    vector<int> Sajz;

    vector<char> Type;

public:
    inline void read_data()
    {
        cin >> N >> M;

        Miasto.resize(N + 1);
        Kraw.resize(M);
        Rep.resize(N + 1);
        Sajz.resize(N + 1, 1);
        Type.resize(N + 1);

        FOR(i, N + 1, 1)
        Rep[i] = i;

        FOR(i, M, 0)
        cin >> Kraw[i].from >> Kraw[i].to >> Kraw[i].cost;

        sort(Kraw.begin(), Kraw.end(), [this](const edge &lhs, const edge &rhs)
             { return lhs.cost < rhs.cost; });
    }

    inline int fint(int a) { return Rep[a] == a ? a : Rep[a] = fint(Rep[a]); }

    inline void onion(int a, int b, int cost)
    {
        if (fint(a) == fint(b))
            return;

        if (Sajz[fint(a)] < Sajz[fint(b)])
            swap(a, b);

        Sajz[fint(a)] += Sajz[fint(b)];
        Sajz[fint(b)] = 0;

        Rep[fint(b)] = fint(a);

        Miasto[a].push_back({a, b, cost});
        Miasto[b].push_back({b, a, cost});
    }

    inline void kolorowanie(int v, int p, int type)
    {
        if (type == 0)
            Type[v] = 'M';
        else
            Type[v] = 'B';

        for (auto w : Miasto[v])
            if (w.to != p)
                kolorowanie(w.to, v, type ^ 1);
    }

    inline void solve()
    {
        read_data();

        // create MST

        FOR(i, M, 0)
        onion(Kraw[i].from, Kraw[i].to, Kraw[i].cost);

        kolorowanie(1, 1, 0);

        FOR(i, N + 1, 1)
        cout << Type[i];

        cout << '\n';

        // sprawdzenie min kosztu

        // ll niezadowolenie = 0;

        // FOR(i, N + 1, 1)
        // {

        //     ll niezadowolenie_v = INF;
        //     for (auto w : Miasto[i])
        //         niezadowolenie_v = min(niezadowolenie_v, (ll)w.cost);

        //     niezadowolenie = max(niezadowolenie, niezadowolenie_v);
        // }

        // cout << niezadowolenie << '\n';
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