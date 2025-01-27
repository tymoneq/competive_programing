#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    static const int M = 5e5 + 10;
    int N;
    int res = 0;

    struct rozmiar
    {
        int ile_parzystych;
        int ile_nieparzystych;
    };

    vector<bool> Jednostki;
    vector<int> Rep;
    vector<rozmiar> Sajz;

public:
    inline int fint(int a) { return Rep[a] == a ? a : Rep[a] = fint(Rep[a]); }

    inline void solve()
    {
        cin >> N;

        Jednostki.resize(M);
        Rep.resize(M);
        Sajz.resize(M);

        FOR(i, M, 1)
        Rep[i] = i;

        while (N--)
        {
            int nowa_jednostka;

            cin >> nowa_jednostka;

            if (Jednostki[nowa_jednostka])
            {
                cout << res << ' ';
                continue;
            }

            Jednostki[nowa_jednostka] = true;

            if (nowa_jednostka % 2 == 0)
                Sajz[nowa_jednostka].ile_parzystych = 1;
            else
                Sajz[nowa_jednostka].ile_nieparzystych = 1;

            // uptdate result

            if (Jednostki[nowa_jednostka - 1] && Jednostki[nowa_jednostka + 1])
            {
                int rep_left = fint(nowa_jednostka - 1);
                int rep_right = fint(nowa_jednostka + 1);

                res -= max(Sajz[rep_left].ile_nieparzystych, Sajz[rep_left].ile_parzystych);
                res -= max(Sajz[rep_right].ile_nieparzystych, Sajz[rep_right].ile_parzystych);

                Sajz[nowa_jednostka].ile_nieparzystych += Sajz[rep_left].ile_nieparzystych + Sajz[rep_right].ile_nieparzystych;
                Sajz[nowa_jednostka].ile_parzystych += Sajz[rep_left].ile_parzystych + Sajz[rep_right].ile_parzystych;

                res += max(Sajz[nowa_jednostka].ile_nieparzystych, Sajz[nowa_jednostka].ile_parzystych);

                Rep[rep_left] = nowa_jednostka;
                Rep[rep_right] = nowa_jednostka;

                Sajz[rep_left] = {0, 0};
                Sajz[rep_right] = {0, 0};
            }

            else if (Jednostki[nowa_jednostka - 1])
            {
                int rep_left = fint(nowa_jednostka - 1);
                res -= max(Sajz[rep_left].ile_nieparzystych, Sajz[rep_left].ile_parzystych);

                Sajz[nowa_jednostka].ile_nieparzystych += Sajz[rep_left].ile_nieparzystych;
                Sajz[nowa_jednostka].ile_parzystych += Sajz[rep_left].ile_parzystych;

                res += max(Sajz[nowa_jednostka].ile_nieparzystych, Sajz[nowa_jednostka].ile_parzystych);

                Rep[rep_left] = nowa_jednostka;

                Sajz[rep_left] = {0, 0};
            }
            else if (Jednostki[nowa_jednostka + 1])
            {
                int rep_right = fint(nowa_jednostka + 1);

                res -= max(Sajz[rep_right].ile_nieparzystych, Sajz[rep_right].ile_parzystych);

                Sajz[nowa_jednostka].ile_nieparzystych += Sajz[rep_right].ile_nieparzystych;
                Sajz[nowa_jednostka].ile_parzystych += Sajz[rep_right].ile_parzystych;

                res += max(Sajz[nowa_jednostka].ile_nieparzystych, Sajz[nowa_jednostka].ile_parzystych);
                Rep[rep_right] = nowa_jednostka;

                Sajz[rep_right] = {0, 0};
            }
            else
                res++;
                
            cout << res << ' ';
        }

        cout << '\n';
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