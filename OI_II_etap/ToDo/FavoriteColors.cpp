#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, M;
    vector<vector<int>> Graf;
    set<int> DostepneKolory;
    vector<int> KolorSajz;
    vector<int> KolorWierzcholka;
    vector<vector<int>> PodziwnianyPrzez;
    vector<int> ReprezentantKolorow;
    map<int, int> LegendaKolorow;

public:
    inline int fint(int v) { return ReprezentantKolorow[v] == v ? v : fint(ReprezentantKolorow[v]); }

    inline void read_data()
    {
        cin >> N >> M;

        Graf.resize(N + 1);
        KolorSajz.resize(N + 1);
        KolorWierzcholka.resize(N + 1);
        ReprezentantKolorow.resize(N + 1);
        PodziwnianyPrzez.resize(N + 1);

        FOR(i, N + 1, 1)
        DostepneKolory.insert(i);

        FOR(i, M, 0)
        {
            int a, b;
            cin >> a >> b;
            Graf[b].push_back(a);
        }

        FOR(i, N + 1, 1)
        ReprezentantKolorow[i] = i;
    }

    inline void changeColor(int v, int color)
    {
        for (int somsiad : Graf[v])
        {
            if (KolorWierzcholka[somsiad] == color)
                continue;

            int reprezentantSomsiad = fint(KolorWierzcholka[somsiad]);

            if (reprezentantSomsiad != color)
            {
                KolorSajz[color] += (reprezentantSomsiad == 0 ? 1 : KolorSajz[ReprezentantKolorow[KolorWierzcholka[somsiad]]]);
                KolorSajz[ReprezentantKolorow[KolorWierzcholka[somsiad]]] = 0;
                ReprezentantKolorow[KolorWierzcholka[somsiad]] = color;
            }
            KolorWierzcholka[somsiad] = color;
        }
        PodziwnianyPrzez[KolorWierzcholka[v]].push_back(color);
    }
    inline void solve()
    {
        read_data();

        FOR(i, N + 1, 1)
        {
            int colorSynow = 0, rozmiar = 0;
            if (KolorWierzcholka[i] == 0)
            {
                KolorWierzcholka[i] = *DostepneKolory.begin();
                DostepneKolory.erase(DostepneKolory.begin());
                KolorSajz[KolorWierzcholka[i]] = 1;
            }
            else
                for (int w : PodziwnianyPrzez[KolorWierzcholka[i]])
                    if (rozmiar < KolorSajz[fint(KolorWierzcholka[w])])
                    {
                        rozmiar = KolorSajz[w];
                        colorSynow = fint(KolorWierzcholka[w]);
                    }

            for (int somsiad : Graf[i])
            {
                if (KolorWierzcholka[somsiad] == 0)
                    continue;

                int kolor = fint(KolorWierzcholka[somsiad]);
                if (KolorSajz[kolor] > rozmiar)
                {
                    rozmiar = KolorSajz[kolor];
                    colorSynow = kolor;
                }
            }

            if (colorSynow == 0)
            {
                for (int somsiad : Graf[i])
                {
                    KolorSajz[*DostepneKolory.begin()] += 1;
                    KolorWierzcholka[somsiad] = *DostepneKolory.begin();
                }

                PodziwnianyPrzez[KolorWierzcholka[i]].push_back(*DostepneKolory.begin());
                DostepneKolory.erase(DostepneKolory.begin());
            }
            else
                changeColor(i, colorSynow);
        }

        FOR(i, N + 1, 1)
        KolorWierzcholka[i] = fint(KolorWierzcholka[i]);

        FOR(i, N + 1, 1)
        cout << KolorWierzcholka[i] << '\n';
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