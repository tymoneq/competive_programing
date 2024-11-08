#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int base = 1 << 19, N = 3e5 + 10;

struct Wieza
{
    int x, s, a, pocz_zakresu, koniec_zakresu;
};

set<int> TreeTypWiezy[base << 1];
int SegmentTree[base << 1];
Wieza WiezeWMiastach[N];

inline ll quessHowManyA(ll a, ll x, ll pocz)
{
    ll lo = 0, hi = N, mid, ans = 0;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (pocz + (a * mid) <= (x - 1))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

inline int lazypropagation(int typWiezy, int poczPrzedzialu, int srodek)
{
    int sum = 0;
    if (srodek < WiezeWMiastach[typWiezy].pocz_zakresu || poczPrzedzialu > WiezeWMiastach[typWiezy].koniec_zakresu)
        return 0;

    int liczonyPoczPrzedzialu = max(poczPrzedzialu, WiezeWMiastach[typWiezy].pocz_zakresu);
    int liczonyKoniecPrzedzialu = min(srodek, WiezeWMiastach[typWiezy].koniec_zakresu);

    if (liczonyPoczPrzedzialu < WiezeWMiastach[typWiezy].x)
    {
        // przedział kończy się przed X
        ll ilosc = quessHowManyA(WiezeWMiastach[typWiezy].a, WiezeWMiastach[typWiezy].x, liczonyPoczPrzedzialu);
        int a0 = WiezeWMiastach[typWiezy].x - 1 - ilosc * WiezeWMiastach[typWiezy].a;

        sum += (a0 * 2 + (ilosc - 1) * WiezeWMiastach[typWiezy].a) / 2 * ilosc;

        // przedział kończy się na X
        if (liczonyKoniecPrzedzialu >= WiezeWMiastach[typWiezy].x)
            sum += WiezeWMiastach[typWiezy].s;

        if (liczonyKoniecPrzedzialu > WiezeWMiastach[typWiezy].x)
        {
            ilosc = quessHowManyA(WiezeWMiastach[typWiezy].a, WiezeWMiastach[typWiezy].x, liczonyKoniecPrzedzialu);
            a0 = WiezeWMiastach[typWiezy].x - 1 - ilosc * WiezeWMiastach[typWiezy].a;

            sum += (a0 * 2 + (ilosc - 1) * WiezeWMiastach[typWiezy].a) / 2 * ilosc;
        }
    }

    else if (liczonyPoczPrzedzialu >= WiezeWMiastach[typWiezy].x)
    {
        // przedzial zaczyna się na X
        if (liczonyPoczPrzedzialu == WiezeWMiastach[typWiezy].x)
            sum += WiezeWMiastach[typWiezy].s;

        ll ilosc = quessHowManyA(WiezeWMiastach[typWiezy].a, WiezeWMiastach[typWiezy].x, liczonyKoniecPrzedzialu);
        int a0 = WiezeWMiastach[typWiezy].x - 1 - ilosc * WiezeWMiastach[typWiezy].a;

        sum += (a0 * 2 + (ilosc - 1) * WiezeWMiastach[typWiezy].a) / 2 * ilosc;
    }
    return sum;
}

inline void dodajNowaWieze(int idWiezy, int val, int poczPrzedzialu, int koniecPrzedz, int idV)
{
    if (poczPrzedzialu > WiezeWMiastach[idWiezy].koniec_zakresu || koniecPrzedz < WiezeWMiastach[idWiezy].pocz_zakresu)
        return;

    if (WiezeWMiastach[idWiezy].pocz_zakresu <= poczPrzedzialu && koniecPrzedz <= WiezeWMiastach[idWiezy].koniec_zakresu)
    {
        SegmentTree[idV] += val;
        TreeTypWiezy[idV].insert(idWiezy);
        return;
    }

    int mid = poczPrzedzialu + (koniecPrzedz - poczPrzedzialu) / 2;

    int lewySynWartosc = lazypropagation(idWiezy, poczPrzedzialu, mid);
    int prawySyn = val - lewySynWartosc;

    // rekurencja do synów
    dodajNowaWieze(idWiezy, lewySynWartosc, poczPrzedzialu, mid, idV * 2);
    dodajNowaWieze(idWiezy, prawySyn, mid + 1, koniecPrzedz, idV * 2 + 1);

    SegmentTree[idV] += val;
}

inline void OdejmijWieze(int idWiezy, int val, int poczPrzedzialu, int koniecPrzedz, int idV)
{
    if (poczPrzedzialu > WiezeWMiastach[idWiezy].koniec_zakresu || koniecPrzedz < WiezeWMiastach[idWiezy].pocz_zakresu)
        return;

    if (WiezeWMiastach[idWiezy].pocz_zakresu <= poczPrzedzialu && koniecPrzedz <= WiezeWMiastach[idWiezy].koniec_zakresu)
    {
        SegmentTree[idV] -= val;
        TreeTypWiezy[idV].erase(idWiezy);
        return;
    }

    int mid = poczPrzedzialu + (koniecPrzedz - poczPrzedzialu) / 2;

    int lewySynWartosc = lazypropagation(idWiezy, poczPrzedzialu, mid);
    int prawySyn = val - lewySynWartosc;

    // rekurencja do synów
    dodajNowaWieze(idWiezy, lewySynWartosc, poczPrzedzialu, mid, idV * 2);
    dodajNowaWieze(idWiezy, prawySyn, mid + 1, koniecPrzedz, idV * 2 + 1);

    SegmentTree[idV] -= val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    char A;
    int x, s, a, x2;
    while (m--)
    {
        cin >> A;
        if (A == 'P')
        {
            cin >> x >> s >> a;
            int pocz = x - (s / a), koniec = x + (s / a);
            WiezeWMiastach[x] = {x, s, a, pocz, koniec};

            int val = (a * (x - pocz) + s);

            dodajNowaWieze(x, val, 1, base, 1);
        }
        else if (A == 'U')
        {
            cin >> x;

            int val = (WiezeWMiastach[x].a * (x - WiezeWMiastach[x].pocz_zakresu) + WiezeWMiastach[x].s);

            OdejmijWieze(x, val, 1, base, 1);
        }
        else
        {
            cin >> x >> x2;
            cout << querry(x, x2, 1, base) / (x2 - x + 1) << "\n";
        }
    }

    return 0;
}
