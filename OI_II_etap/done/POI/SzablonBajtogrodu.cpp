#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct edge
{
    int to, id;
    string kod;
};

class Solve
{
protected:
    int n;
    set<string> Szablony;
    vector<vector<edge>> Bajtogrod;
    set<int> OdwiedzoneKrawedzie;
    vector<string> PoprawneSzablony;

public:
    inline void read_data()
    {
        cin >> n;
        Bajtogrod.resize(n + 1);
        FOR(i, n - 1, 0)
        {
            int a, b;
            string c;
            cin >> a >> b >> c;
            Bajtogrod[a].push_back({b, i, c});
            Bajtogrod[b].push_back({a, i, c});
        }
    }

    inline int ZnajdzLisc(int v, int p)
    {
        if (Bajtogrod[v].size() == 1)
            return v;

        for (auto w : Bajtogrod[v])
            if (w.to != p)
                return ZnajdzLisc(w.to, v);

        return v;
    }

    inline void ZnajdzSzablony(int v, int p, string szablon)
    {
        for (auto w : Bajtogrod[v])
            if (w.to != p)
            {
                string nowySablon = szablon + w.kod;
                Szablony.insert(nowySablon);
                ZnajdzSzablony(w.to, v, nowySablon);
            }
    }

    inline void generujSzablony()
    {
        int lisc = ZnajdzLisc(1, 1);
        ZnajdzSzablony(lisc, lisc, "");
        for (auto szablon : Szablony)
        {
            string NowySzablon = "";
            for (int i = szablon.size() - 1; i >= 0; i--)
                NowySzablon += szablon[i];
            Szablony.insert(NowySzablon);
        }
    }

    inline void Sprawdz(int v, int p, const string WzorSzablonu, string &aktualnySzablon, vector<int> &Krawedzie)
    {
        if ((aktualnySzablon.size() == WzorSzablonu.size()) && WzorSzablonu == aktualnySzablon)
        {
            for (int &w : Krawedzie)
                OdwiedzoneKrawedzie.insert(w);
            return;
        }

        if (aktualnySzablon.size() > WzorSzablonu.size())
            return;

        for (auto &w : Bajtogrod[v])
            if (w.to != p)
            {
                aktualnySzablon += w.kod;
                Krawedzie.push_back(w.id);
                Sprawdz(w.to, v, WzorSzablonu, aktualnySzablon, Krawedzie);
                Krawedzie.pop_back();
                aktualnySzablon.pop_back();
            }
    }

    inline void SprawdzSzablony()
    {
        vector<int> Krawedzie;
        for (string szablon : Szablony)
        {
            OdwiedzoneKrawedzie.clear();

            FOR(i, n + 1, 1)
            {
                string aktualnySzablon = "";
                Sprawdz(i, i, szablon, aktualnySzablon, Krawedzie);
            }

            if (OdwiedzoneKrawedzie.size() == n - 1)
                PoprawneSzablony.push_back(szablon);
        }

        cout << PoprawneSzablony.size() << '\n';
        for (auto szablon : PoprawneSzablony)
            cout << szablon << '\n';
    }

    inline void solve()
    {

        read_data();
        generujSzablony();
        SprawdzSzablony();
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