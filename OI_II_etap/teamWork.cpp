#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int n, rozmiarDruzyny;
    multiset<int> Umiejetnosci;

    int wynik = 0;

public:
    inline void read_data()
    {
        cin >> n >> rozmiarDruzyny;

        FOR(i, n, 0)
        {
            int a;
            cin >> a;
            Umiejetnosci.insert(a);
        }
    }
    inline void solve()
    {
        read_data();

        while (!Umiejetnosci.empty())
        {
            auto NajlepszaWgrupie = Umiejetnosci.end();
            --NajlepszaWgrupie;
            
            int WartoscNajlepszaWgrupie = *NajlepszaWgrupie;
            Umiejetnosci.erase(NajlepszaWgrupie);

            wynik += WartoscNajlepszaWgrupie;

            int i = 1;
            while (i < rozmiarDruzyny && !Umiejetnosci.empty())
            {
                wynik += WartoscNajlepszaWgrupie;
                Umiejetnosci.erase(Umiejetnosci.begin());
                i++;
            }
        }

        cout << wynik << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("teamwork.in", "r", stdin);
    // freopen("teamwork.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}