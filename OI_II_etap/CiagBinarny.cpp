#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct Zapytanie
{
    int poczontek, koniec, ilosc_zmian, id;
};

class Solve
{
protected:
    static const int Pierwiastek = 380;
    int n, q;
    vector<int> ElementyCiagu;
    int lewy_koniec = 0, prawy_koniec = 0;
    multiset<int, greater<int>> Wartosci_w_srodku;
    vector<Zapytanie> zapytania;
    vector<int> Odpowiedzi;

public:
    static inline bool moSort(const Zapytanie &lhs, const Zapytanie &rhs)
    {
        if (lhs.poczontek / Pierwiastek == rhs.poczontek / Pierwiastek)
            return lhs.koniec < rhs.koniec;

        return lhs.poczontek / Pierwiastek < rhs.poczontek / Pierwiastek;
    }

    inline void read_data()
    {
        cin >> n >> q;
        zapytania.resize(q);
        Odpowiedzi.resize(q);

        FOR(i, n + 1, 1)
        {
            int ile;
            cin >> ile;

            int wartosc = (i % 2 == 1 ? 1 : 0);
            FOR(j, ile, 0)
            ElementyCiagu.push_back(wartosc);
        }
        FOR(i, q, 0)
        {
            cin >> zapytania[i].poczontek >> zapytania[i].koniec >> zapytania[i].ilosc_zmian;
            zapytania[i].id = i;
        }

        sort(zapytania.begin(), zapytania.end(), moSort);
    }
    inline void solve()
    {
        read_data();

        int lewy_wskaznik = 0, prawy_wskaznik = 0;

        for (auto zapytanie : zapytania)
        {
        }

        FOR(i, q, 0)
        cout << Odpowiedzi[i] << '\n';
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