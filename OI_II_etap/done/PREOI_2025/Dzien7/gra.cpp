#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;
class Solve
{
protected:
    int N, K;
    struct gracz
    {
        vector<ll> Umiejetnosci;
        vector<ll> ZyskUmiejetnosci;
    };

    struct graczComparator
    {
        bool operator()(const gracz &lhs, const gracz &rhs) const
        {
            FOR(i, rhs.Umiejetnosci.size(), 0)
            {
                if (lhs.Umiejetnosci[i] == rhs.Umiejetnosci[i])
                    continue;

                return lhs.Umiejetnosci[i] < rhs.Umiejetnosci[i];
            }
            return false;
        }
    };

    int res = 0;
    gracz skillBajtka;

    multiset<gracz, graczComparator> Gracze;
    vector<gracz> G;

public:
    inline void read_data()
    {
        cin >> N >> K;

        G.resize(N);

        FOR(i, N, 0)
        {
            G[i].Umiejetnosci.resize(K);
            G[i].ZyskUmiejetnosci.resize(K);
            FOR(j, K, 0)
            cin >> G[i].Umiejetnosci[j];
        }
        FOR(i, N, 0)
        FOR(j, K, 0)
        cin >> G[i].ZyskUmiejetnosci[j];

        for (auto g : G)
            Gracze.insert(g);

        skillBajtka.Umiejetnosci.resize(K, 0);
        skillBajtka.ZyskUmiejetnosci.resize(K, 0);
    }
    inline void solve()
    {

        read_data();

        bool moved = true;

        while (moved && !Gracze.empty())
        {
            moved = false;

            vector<gracz> To_erase;
            auto it = Gracze.upper_bound(skillBajtka);

            for (auto itr = Gracze.begin(); itr != it; itr++)
            {
                bool wrong = false;
                FOR(i, K, 0)
                if (skillBajtka.Umiejetnosci[i] < itr->Umiejetnosci[i])
                {
                    wrong = true;
                    break;
                }
                if (wrong)
                    continue;

                moved = true;
                To_erase.push_back(*itr);
                res++;

                FOR(i, K, 0)
                skillBajtka.Umiejetnosci[i] += itr->ZyskUmiejetnosci[i];
            }

            for (auto w : To_erase)
            {
                if (Gracze.find(w) == Gracze.end())
                    continue;

                Gracze.erase(w);
            }
        }

        cout << res << '\n';
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