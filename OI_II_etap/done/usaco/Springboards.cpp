#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

constexpr int base = 1 << 18;

int Tree[base << 1];

class Solve
{
protected:
    struct point
    {
        int PointX, PointY;
        int id;
        bool czyPoczatek;
    };

    int N, ans, P;
    vector<int> WartosciWPunkcje;
    vector<int> IleOszczedza;
    vector<point> Punkty;
    map<int, int> IDxWDrzewie;

public:
    inline void read_data()
    {
        cin >> N >> P;

        WartosciWPunkcje.resize(P);
        IleOszczedza.resize(P);

        FOR(i, P, 0)
        {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            Punkty.push_back({x1, y1, i, true});
            Punkty.push_back({x2, y2, i, false});

            IleOszczedza[i] = (x2 - x1) + (y2 - y1);

            IDxWDrzewie[x1] = 0;
            IDxWDrzewie[x2] = 0;
        }

        int id_w_drzewie = 0;

        for (auto &el : IDxWDrzewie)
        {
            id_w_drzewie++;
            el.second = id_w_drzewie;
        }

        sort(Punkty.begin(), Punkty.end(), [this](const point &lhs, const point &rhs)
             {
            if(lhs.PointY == rhs.PointY)
                return lhs.PointX < rhs.PointX;
                
            return lhs.PointY < rhs.PointY; });
    }

    inline void upt(int v)
    {
        v /= 2;

        while (v > 0)
        {
            Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
            v /= 2;
        }
    }

    inline int query(int r)
    {
        r = IDxWDrzewie[r] + base + 1;
        int l = base;
        int res = 0;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                res = max(res, Tree[l + 1]);

            if (r % 2 == 1)
                res = max(res, Tree[r - 1]);

            r /= 2, l /= 2;
        }

        return res;
    }

    inline void solve()
    {
        read_data();

        for (auto punkt : Punkty)
        {
            if (!punkt.czyPoczatek)
            {
                int val = WartosciWPunkcje[punkt.id];
                int id_na_drzewie = IDxWDrzewie[punkt.PointX];

                Tree[id_na_drzewie + base] = max(Tree[id_na_drzewie + base], val);
                upt(id_na_drzewie + base);
            }
            else
            {
                int wartosc_po_uzyciu_punktu = query(punkt.PointX) + IleOszczedza[punkt.id];
                WartosciWPunkcje[punkt.id] = wartosc_po_uzyciu_punktu;
            }
        }

        int max_oszczednosc = Tree[1];
        ans = N + N - max_oszczednosc;

        cout << ans << '\n';
    };
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}