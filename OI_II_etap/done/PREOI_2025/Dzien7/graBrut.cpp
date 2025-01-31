#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    struct gracz
    {
        vector<int> Umiejetnosci;
        vector<int> ZyskUmiejetnosci;
    };

    int N, K;
    int res = 0;
    vector<gracz> Gracze;
    vector<ll> skillBajtka;
    vector<bool> Pokonani;

public:
    inline void read_data()
    {
        cin >> N >> K;

        Gracze.resize(N);
        Pokonani.resize(N, false);
        skillBajtka.resize(K, 0);

        FOR(i, N, 0)
        {
            Gracze[i].Umiejetnosci.resize(K);
            Gracze[i].ZyskUmiejetnosci.resize(K);
            FOR(j, K, 0)
            cin >> Gracze[i].Umiejetnosci[j];
        }
        FOR(i, N, 0)
        FOR(j, K, 0)
        cin >> Gracze[i].ZyskUmiejetnosci[j];
    }

    inline void solve()
    {
        read_data();

        if (K == 1)
        {
            sort(Gracze.begin(), Gracze.end(), [this](const gracz &lhs, const gracz &rhs)
                 { return lhs.Umiejetnosci[0] < rhs.Umiejetnosci[0]; });

            FOR(i, N, 0)
            if (skillBajtka[0] >= Gracze[i].Umiejetnosci[0])
            {
                skillBajtka[0] += Gracze[i].ZyskUmiejetnosci[0];
                res++;
            }
        }
        else
        {
            bool moved = true;
            while (moved)
            {
                moved = false;

                FOR(i, N, 0)
                {
                    if (Pokonani[i])
                        continue;

                    bool BajtekPokona = true;

                    FOR(j, K, 0)
                    if (Gracze[i].Umiejetnosci[j] > skillBajtka[j])
                    {
                        BajtekPokona = false;
                        break;
                    }

                    if (BajtekPokona)
                    {
                        moved = true;
                        res++;
                        Pokonani[i] = true;

                        FOR(j, K, 0)
                        skillBajtka[j] += Gracze[i].ZyskUmiejetnosci[j];
                    }
                }
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