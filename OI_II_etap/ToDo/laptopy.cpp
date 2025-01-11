#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

struct uczniowie
{
    ll ileWolnegoMiejscaPoLewej, ileWolnegoMiejscaPoPrawek;
    int idUczniaPoLewej = -1, idUczniaPoPrawej = -1;
};

struct uczniowiecomparator
{
    bool operator()(const uczniowie &lhs, const uczniowie &rhs) const
    {
        return (lhs.ileWolnegoMiejscaPoLewej + lhs.ileWolnegoMiejscaPoPrawek) > (rhs.ileWolnegoMiejscaPoLewej + rhs.ileWolnegoMiejscaPoPrawek);
    };
};

class Solve
{
protected:
    struct uczenWLawce
    {
        ll odlegosc_od_lewego_konca;
        int id;
    };

    int N, Q;
    ll DlugoscLaptopa, DlugoscLawki, IloscLawek;
    ll Ile_moznaDostawic = 0;
    ll MAXM_do_ktorego_mozna_ustawic = 0;
    vector<vector<uczenWLawce>> Lawki; // id Ucznia w ławce

    set<uczniowie, uczniowiecomparator> Uczniowie;

public:
    inline void read_data()
    {
        cin >> N >> Q >> DlugoscLaptopa >> IloscLawek >> DlugoscLawki;

        Lawki.resize(IloscLawek + 1);

        FOR(i, N + 1, 1)
        {
            int id_lawki;
            ll odlegosc;
            cin >> id_lawki >> odlegosc;

            Lawki[id_lawki].push_back({odlegosc, i});
        }

        FOR(i, IloscLawek + 1, 1)
        sort(Lawki[i].begin(), Lawki[i].end(), [this](const uczenWLawce &lhs, const uczenWLawce &rhs)
             { return lhs.odlegosc_od_lewego_konca < rhs.odlegosc_od_lewego_konca; });
    }

    inline void get_min_m()
    {
        FOR(i, IloscLawek + 1, 1)
        {
            ll poczontek = 0;
            for (auto uczen : Lawki[i])
            {
                Ile_moznaDostawic += (uczen.odlegosc_od_lewego_konca - poczontek) / DlugoscLaptopa;
                poczontek = uczen.odlegosc_od_lewego_konca + DlugoscLaptopa;
            }
        }
    }

    inline void create_set()
    {
        FOR(i, IloscLawek + 1, 1)
        FOR(j, Lawki[i].size(), 0)
        {
            int idLewego = -1, idPrawego = -1;
            ll dystans_po_lewej = 0;
            ll dystans_po_prawej = 0;
            if (j != 0)
            {
                dystans_po_lewej = (Lawki[i][j].odlegosc_od_lewego_konca - (Lawki[i][j - 1].odlegosc_od_lewego_konca + DlugoscLaptopa)) % DlugoscLaptopa;
                idLewego = j - 1;
            }
            if (j != Lawki[i].size() - 1)
            {
                dystans_po_prawej = (Lawki[i][j + 1].odlegosc_od_lewego_konca - (Lawki[i][j].odlegosc_od_lewego_konca + DlugoscLaptopa)) % DlugoscLaptopa;
                idPrawego = j + 1;
            }

            if (j == 0)
                dystans_po_lewej = Lawki[i][0].odlegosc_od_lewego_konca % DlugoscLaptopa;

            if (j == Lawki[i].size() - 1)
                dystans_po_prawej = (DlugoscLawki - (Lawki[i][j].odlegosc_od_lewego_konca + DlugoscLaptopa)) % DlugoscLaptopa;

            if (dystans_po_lewej + dystans_po_prawej < DlugoscLaptopa)
                continue;

            Uczniowie.insert({dystans_po_lewej, dystans_po_prawej, idLewego, idPrawego});
        }
    }

    inline void solve()
    {
        read_data();

        // policz min do którego mogę dostawiać z wynikiem 0
        get_min_m();

        // PrzygotujDane

        create_set();

        while (Q--)
        {
            ll m;
            cin >> m;
            if (m <= Ile_moznaDostawic)
            {
                cout << 0 << '\n';
                continue;
            }
        }
    };
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