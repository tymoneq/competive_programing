#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

#warning change base 1<<18
constexpr int base = 1 << 18;
struct node
{
    int res;
    char first_character, last_character;
};

node SegmentTree[base << 1];

class Solve
{
protected:
    vector<int> Permutation;
    vector<int> Indexy;
    vector<int> Res;
    vector<vector<int>> KoniecZapytania;

    int N;
    const char Lo = 'L';
    const char Hi = 'H';

public:
    inline void read_data()
    {
        cin >> N;

        Permutation.resize(N);
        Indexy.resize(N + 2);
        Res.resize(N + 1);
        KoniecZapytania.resize(N);

        FOR(i, N, 0)
        {
            cin >> Permutation[i];
            Indexy[Permutation[i]] = i;
        }

        KoniecZapytania[Indexy[1]].push_back(0);

        FOR(i, N + 1, 1)
        {
            int mxRange = max(Indexy[i], Indexy[i + 1]);
            KoniecZapytania[mxRange].push_back(i);
        }
    }

    inline void add(const int v, const int poczontekPrzedzialu, const int koniecPrzedzialu, const int PoczontekZapytania, const int KoniecZapytania, const char wartosc)
    {
        if (poczontekPrzedzialu > KoniecZapytania || koniecPrzedzialu < PoczontekZapytania)
            return;

        if (PoczontekZapytania <= poczontekPrzedzialu && koniecPrzedzialu <= KoniecZapytania)
        {
            if (SegmentTree[v].first_character != Lo && SegmentTree[v].first_character != Hi)
                SegmentTree[v].first_character = wartosc;

            if (SegmentTree[v].last_character == Hi && wartosc == Lo)
                SegmentTree[v].res++;

            SegmentTree[v].last_character = wartosc;

            return;
        }

        int lewySyn = v * 2, prawySyn = v * 2 + 1;
        int mid = poczontekPrzedzialu + (koniecPrzedzialu - poczontekPrzedzialu) / 2;

        SegmentTree[lewySyn].res += SegmentTree[v].res;
        SegmentTree[prawySyn].res += SegmentTree[v].res;

        if (SegmentTree[lewySyn].last_character == Hi && SegmentTree[v].first_character == Lo)
            SegmentTree[lewySyn].res++;

        if (SegmentTree[prawySyn].last_character == Hi && SegmentTree[v].first_character == Lo)
            SegmentTree[prawySyn].res++;

        if (SegmentTree[v].last_character == Lo || SegmentTree[v].last_character == Hi)
        {
            SegmentTree[lewySyn].last_character = SegmentTree[v].last_character;
            SegmentTree[prawySyn].last_character = SegmentTree[v].last_character;
        }

        SegmentTree[v].res = 0;
        SegmentTree[v].last_character = ' ';
        SegmentTree[v].first_character = ' ';

        add(lewySyn, poczontekPrzedzialu, mid, PoczontekZapytania, KoniecZapytania, wartosc);
        add(prawySyn, mid + 1, koniecPrzedzialu, PoczontekZapytania, KoniecZapytania, wartosc);
    }

    inline int query(int v)
    {
        node res = SegmentTree[v];

        while (v > 1)
        {
            v /= 2;
            res.res += SegmentTree[v].res;
            if (res.last_character == Hi && SegmentTree[v].first_character == Lo)
                res.res++;

            if (SegmentTree[v].last_character == Lo || SegmentTree[v].last_character == Hi)
                res.last_character = SegmentTree[v].last_character;
        }

        return res.res;
    }

    inline void solve()
    {
        read_data();

        FOR(i, N, 0)
        {
            // dodaj na drzewo przedziałowe Hi dla elementów mniejszych od Permutation[i], Lo do elementów większych równych Per[i]

            add(1, 0, base - 1, Permutation[i], base - 1, Lo);
            add(1, 0, base - 1, 0, Permutation[i] - 1, Hi);

            // przetwórz zapytania
            for (int zapytanie : KoniecZapytania[i])
                Res[zapytanie] = query(zapytanie + base);
        }

        FOR(i, N + 1, 0)
        cout << Res[i] << '\n';
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