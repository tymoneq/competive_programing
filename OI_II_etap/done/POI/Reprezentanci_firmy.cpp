#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

#warning change BASE =1 <<18
constexpr int base = 1 << 18;

struct pracownik
{
    int val, id;
};

int PrzedzialyTree[base << 1];
pracownik Pracownicy[base << 1];
typedef long long ll;

class Solve
{
protected:
    struct Przedzial
    {
        int poczontek, koniec, ile_trzeba;
    };

    int N, M;
    const int INF = 1e9 + 5;
    ll res = 0;
    vector<int> PracownicyODP;
    vector<Przedzial> Przedzialy;

public:
    inline void read_data()
    {
        FOR(i, base * 2, 0)
        Pracownicy[i].val = INF;

        cin >> N;

        FOR(i, N + 1, 1)
        {
            cin >> Pracownicy[i + base].val;
            Pracownicy[i + base].id = i;
        }
        cin >> M;
        Przedzialy.resize(M);

        FOR(i, M, 0)
        cin >> Przedzialy[i].poczontek >> Przedzialy[i].koniec >> Przedzialy[i].ile_trzeba;
    }

    inline int queryPrzedzial(int l, int r)
    {
        int suma = 0;
        l += base, r += base;

        l--;
        r++;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                suma += PrzedzialyTree[l + 1];
            if (r % 2 == 1)
                suma += PrzedzialyTree[r - 1];

            r /= 2, l /= 2;
        }

        return suma;
    }

    inline pracownik find_pracownik(int l, int r)
    {
        pracownik najtanszyPracownik;
        najtanszyPracownik.val = INF;
        l += base, r += base;

        l--;
        r++;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0 && najtanszyPracownik.val > Pracownicy[l + 1].val)
                najtanszyPracownik = Pracownicy[l + 1];

            if (r % 2 == 1 && najtanszyPracownik.val > Pracownicy[r - 1].val)
                najtanszyPracownik = Pracownicy[r - 1];

            r /= 2, l /= 2;
        }

        return najtanszyPracownik;
    }

    inline void uptPrzedzial(int v)
    {
        v /= 2;
        while (v > 0)
        {
            PrzedzialyTree[v] = PrzedzialyTree[v * 2] + PrzedzialyTree[v * 2 + 1];
            v /= 2;
        }
    }
    inline void uptPracownicy(int v)
    {
        v += base;
        v /= 2;
        while (v > 0)
        {
            if (Pracownicy[v * 2].val <= Pracownicy[v * 2 + 1].val)
                Pracownicy[v] = Pracownicy[v * 2];

            else
                Pracownicy[v] = Pracownicy[v * 2 + 1];

            v /= 2;
        }
    }
    inline void solve()
    {
        read_data();

        // upt segment Tree

        FOR(i, N + 1, 1)
        uptPracownicy(i);

        // sortowanie przedzialows
        sort(Przedzialy.begin(), Przedzialy.end(), [this](const Przedzial &lhs, const Przedzial &rhs)
             { return (lhs.koniec - lhs.poczontek) < (rhs.koniec - rhs.poczontek); });

        FOR(i, M, 0)
        {
            // sprawdz ile potrzeba dodać pracownikow na przedziale
            int ile_juz_na_przedziale = queryPrzedzial(Przedzialy[i].poczontek, Przedzialy[i].koniec);
            if (ile_juz_na_przedziale >= Przedzialy[i].ile_trzeba)
                continue;

            int ile_dodac = Przedzialy[i].ile_trzeba - ile_juz_na_przedziale;
            // dodaj na przedziale

            PrzedzialyTree[Przedzialy[i].poczontek + base] += ile_dodac;
            uptPrzedzial(Przedzialy[i].poczontek + base);

            // znajdz najtańszych
            while (ile_dodac--)
            {
                // znaleźć pracownika i zmienic jego wartosc na INF na przedziale
                pracownik kosztPracownika = find_pracownik(Przedzialy[i].poczontek, Przedzialy[i].koniec);
                res += kosztPracownika.val;

                Pracownicy[kosztPracownika.id + base].val = INF;
                uptPracownicy(kosztPracownika.id);

                PracownicyODP.push_back(kosztPracownika.id);
            }
        }

        cout << res << '\n';
        cout << PracownicyODP.size() << '\n';
        for (int w : PracownicyODP)
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