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
        ll ile;
        int to;
    };

    struct wyjscia
    {
        ll ile_w_V = 0;
        ll ile_moze_isc_w_dol = 0;
    };

    int N;
    int Wynik = 0;
    vector<wyjscia> Greedy;
    vector<vector<edge>> Budynek;

public:
    inline void read_data()
    {
        cin >> N;

        Greedy.resize(N + 1);
        Budynek.resize(N + 1);

        FOR(i, N + 1, 1)
        cin >> Greedy[i].ile_w_V;

        FOR(i, N, 1)
        {
            int from, to;
            ll ile;

            cin >> from >> to >> ile;
            Budynek[from].push_back({ile, to});
            Budynek[to].push_back({ile, from});
        }
    }

    inline void dfs(int v, int p)
    {
        edge krawedz_do_ojca = {0, 0};
        // rekurencja do lisci
        for (auto w : Budynek[v])
        {
            if (w.to != p)
                dfs(w.to, v);

            if (w.to == p)
                krawedz_do_ojca = w;
        }

        // zlicznie wyniku
        // najpierw próbuj pozbyć się do podrzewa
        // policz ile może pójść w dół z tego V
        ll ile_w_dol = 0;
        for (auto w : Budynek[v])
            if (w.to != p && (Greedy[v].ile_w_V <= Greedy[w.to].ile_moze_isc_w_dol))
                ile_w_dol = max(Greedy[w.to].ile_moze_isc_w_dol, ile_w_dol);

        if (ile_w_dol != 0)
        {
            Greedy[v].ile_moze_isc_w_dol = ile_w_dol - Greedy[v].ile_w_V;
            Greedy[v].ile_w_V = 0;
        }

        // Jezeli nie możesz przepchnąć w górę to zbuduj wyjście
        if (krawedz_do_ojca.ile < Greedy[v].ile_w_V)
        {
            Wynik++;
            Greedy[v].ile_w_V = 0;
            Greedy[v].ile_moze_isc_w_dol = krawedz_do_ojca.ile;
        }

        else
        {
            krawedz_do_ojca.ile -= Greedy[v].ile_w_V;
            Greedy[krawedz_do_ojca.to].ile_w_V += Greedy[v].ile_w_V;
            Greedy[v].ile_moze_isc_w_dol = min(Greedy[v].ile_moze_isc_w_dol, krawedz_do_ojca.ile);
            Greedy[v].ile_w_V = 0;
        }
    }

    inline void solve()
    {
        read_data();

        dfs(1, 1);

        cout << Wynik << '\n';
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