#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)
typedef long long ll;
constexpr int base = 1 << 20;
int SegmentTree[base << 1];

struct zapytanie
{
    char operacja;
    int val;
};

class Solve
{
protected:
    map<int, int> Wartosci;
    set<int> Indexy;
    multiset<int> AktualneWartosci;
    int m;
    const char Dodaj = '+';
    const char Odejmij = '-';
    const char Zapytaj = '?';
    vector<zapytanie> Zapytania;

public:
    inline int querry(int l, int r)
    {
        int res = 0;
        l--;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                res += SegmentTree[l + 1];

            if (r % 2 == 1)
                res += SegmentTree[r - 1];

            l /= 2, r /= 2;
        }

        return res;
    }

    inline void upt(int v)
    {
        v /= 2;
        while (v > 0)
        {
            SegmentTree[v] = SegmentTree[v * 2] + SegmentTree[v * 2 + 1];
            v /= 2;
        }
    }

    inline int find_best()
    {
        int mx = 0;

        for (int w : AktualneWartosci)
        {
            auto MaxRange_gdy_nieZazdrosci = AktualneWartosci.upper_bound(w * 2);

            int tree_range = 0;

            if (MaxRange_gdy_nieZazdrosci == AktualneWartosci.end())
                tree_range = base + base - 5;
            else
                tree_range = Wartosci[*MaxRange_gdy_nieZazdrosci];

            int res = querry(Wartosci[w], tree_range);

            mx = max(mx, res);

            if (MaxRange_gdy_nieZazdrosci == AktualneWartosci.end())
                break;
        }

        return mx;
    }

    inline void create_segment_tree()
    {
        int tree_index = 1 + base;

        // przypisanie indexów dla wartości
        for (int w : Indexy)
        {
            Wartosci[w] = tree_index;
            tree_index++;
        }
    }

    inline void solve()
    {
        cin >> m;

        Zapytania.resize(m);

        FOR(i, m, 0)
        {
            char operacja;
            int val = 0;
            cin >> operacja;
            if (operacja == Dodaj)
            {
                cin >> val;
                Indexy.insert(val);
            }
            if (operacja == Odejmij)
            {
                cin >> val;
            }
            Zapytania[i] = {operacja, val};
        }

        create_segment_tree();

        for (auto zap : Zapytania)
        {
            if (zap.operacja == Dodaj)
            {
                SegmentTree[Wartosci[zap.val]]++;
                upt(Wartosci[zap.val]);
                AktualneWartosci.insert(zap.val);
            }
            else if (zap.operacja == Odejmij)
            {
                SegmentTree[Wartosci[zap.val]]--;
                upt(Wartosci[zap.val]);

                auto it = AktualneWartosci.find(zap.val);
                AktualneWartosci.erase(it);
            }
            else if (zap.operacja == Zapytaj)
            {
                cout << find_best() << "\n";
            }
        }
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