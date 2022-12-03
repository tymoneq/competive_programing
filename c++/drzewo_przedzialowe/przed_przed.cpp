#include <bits/stdc++.h>
using namespace std;
const int M = (1 << 20); // najmniejsza potęga liczby dwa >= od wielkości przedziału
long long suma[M << 1];  // tablica przechowująca sumę wartości wszystkich liści poddrzewa,
                        // którego korzeniem jest komórka tablicy o danym ideksie
long long obciazenie[M << 1]; // tu przechowujemy obciążenia

void insert(int a, int b, int wartosc)
{
    int l = a + M, r = b + M;
    int dlugosc = 1;
    obciazenie[l] += wartosc;
    suma[l] += wartosc;
    // jeśli przedział nie jest jednoelementowy
    if (l != r)
    {
        obciazenie[r] += wartosc;
        suma[r] += wartosc;
    }
    while (l > 0)
    {
        if (l < r - 1) // jeśli wierzchołki nie mają wspólnego ojca
        {
            if (l % 2 == 0) // jeśli lewy syn na lewej ścieżce
            {
                suma[l + 1] += wartosc * dlugosc;
                obciazenie[l + 1] += wartosc;
            }
            if (r % 2 == 1) // jeśli prawy syn na prawej ścieżce
            {
                suma[r - 1] += wartosc * dlugosc;
                obciazenie[r - 1] += wartosc;
            }
        }

        if (r < M) // jeśli to nie są liście
        {
            suma[l] = suma[l * 2] + suma[l * 2 + 1] + obciazenie[l] * dlugosc;
            suma[r] = suma[r * 2] + suma[r * 2 + 1] + obciazenie[r] * dlugosc;
        }

        // idziemy w kierunku korzenia drzewa
        r >>= 1; // lub r/=2;
        l >>= 1;
        dlugosc <<= 1; // lub dlugosc*=2;
    }
}

long long query(int a, int b)
{
    int l = a + M, r = b + M,
        dl_r, // długość przedziału od prawego krańca
        dl_l; // długość przedziału od lewego krańca
    int dlugosc = 1;
    dl_l = 1;
    if (l != r)
        dl_r = 1;
    else
        dl_r = 0;

    long long wynik = 0;

    while (l > 0) // dopóki nie dotrzemy do korzenia
    {
        wynik += obciazenie[l] * dl_l + obciazenie[r] * dl_r;

        if (l < r - 1) // jeśli wierzchołki nie mają wspólnego ojca
        {
            if (l % 2 == 0) // lewy syn na lewej ścieżce
            {
                wynik += suma[l + 1];
                dl_l += dlugosc;
            }
            if (r % 2 == 1) // prawy syn na prawej ścieżce
            {
                wynik += suma[r - 1];
                dl_r += dlugosc;
            }
        }

        r >>= 1;
        l >>= 1;
        dlugosc <<= 1;
    }
    return wynik;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, option, q, a, b, wartosc;
    cin >> q;
    while (q--)
    {
        cin >> option; // 1 insert, 0 query
        if (option)
        {
            cin >> a >> b >> wartosc;
            insert(a, b, wartosc);
        }
        else
        {
            cin >> a >> b;
            cout << query(a, b) << endl;
        }
    }

    return 0;
}