#include <bits/stdc++.h>

using namespace std;

#define FOR(_name, _upper, _val) for (int(_name) = (_val); (_name) < (_upper); (_name)++)

struct Recommendations
{
    int l, r, id;

};

class Solve
{
protected:
    int n;
    vector<Recommendations> Rekomendacje;
    multiset<int> poczontki;
    multiset<pair<int, int>> konce;
    set<int> zakazane;

public:
    Solve(int _n, vector<Recommendations> _Rekomendacje)
    {
        this->n = _n;
        this->Rekomendacje = _Rekomendacje;
    }

    static inline bool sortowanie(Recommendations &lhs, Recommendations &rhs)
    {
        if (lhs.l == rhs.l)
            return lhs.r > rhs.r;
        return lhs.l < rhs.l;
    }

    inline vector<int> solve()
    {
        vector<int> Wynik(n, 0);
        sort(Rekomendacje.begin(), Rekomendacje.end(), sortowanie);
        FOR(i, n, 1)
        if (Rekomendacje[i].l == Rekomendacje[i - 1].l && Rekomendacje[i].r == Rekomendacje[i - 1].r)
        {
            zakazane.insert(i);
            zakazane.insert(i - 1);
        }

        FOR(i, n, 0)
        {
            if (zakazane.count(i))
            {
                poczontki.insert(Rekomendacje[i].l);
                konce.insert({Rekomendacje[i].r, i});
                continue;
            }
            while (!konce.empty() && konce.begin()->first < Rekomendacje[i].l)
            {
                int id = konce.begin()->second;
                auto it = poczontki.find(Rekomendacje[id].l);

                if (it != poczontki.end())
                    poczontki.erase(it);

                konce.erase(konce.begin());
            }

            int poczontekzakresu = Rekomendacje[i].l;
            int koniecZakres = Rekomendacje[i].r;

            if (poczontki.size() > 0)
            {
                auto it = poczontki.upper_bound(poczontekzakresu);
                it--;
                poczontekzakresu = min(*it, poczontekzakresu);
            }

            auto it = konce.lower_bound({koniecZakres, -1});

            if (it != konce.end())
                koniecZakres = max(koniecZakres, it->first);
            else
                koniecZakres = 0;
            Wynik[Rekomendacje[i].id] = max(koniecZakres - poczontekzakresu + 1 - (Rekomendacje[i].r - Rekomendacje[i].l + 1), 0);

            poczontki.insert(Rekomendacje[i].l);
            konce.insert({Rekomendacje[i].r, i});
        }
        return Wynik;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<Recommendations> Rekomendacje(n);
        FOR(i, n, 0)
        {
            cin >> Rekomendacje[i].l >> Rekomendacje[i].r;
            Rekomendacje[i].id = i;
        }

        Solve rozwiazanie(n, Rekomendacje);

        vector<int> res = rozwiazanie.solve();
        for (int w : res)
            cout << w << '\n';
    }

    return 0;
}