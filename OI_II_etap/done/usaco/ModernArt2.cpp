#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    static const int INF = 1e9 + 5;
    struct range
    {
        int pocz = INF, kon = -1;
    };

    int N;
    vector<int> Paint;
    vector<int> PrefSum;
    vector<range> Zakresy;

    int res = 0;

public:
    inline void read_data()
    {
        cin >> N;

        PrefSum.resize(N + 1);
        Zakresy.resize(N + 1);
        Paint.resize(N);

        FOR(i, N, 0)
        {
            cin >> Paint[i];
            Zakresy[Paint[i]].pocz = min(i, Zakresy[Paint[i]].pocz);
            Zakresy[Paint[i]].kon = max(i, Zakresy[Paint[i]].kon);
        }
    }
    inline void solve()
    {
        read_data();
        FOR(i, N + 1, 1)
        {
            if (Zakresy[i].pocz == INF)
                continue;

            PrefSum[Zakresy[i].pocz]++;
            PrefSum[Zakresy[i].kon + 1]--;
        }

        FOR(i, N, 0)
        PrefSum[i + 1] += PrefSum[i];

        FOR(i, N, 0)
        res = max(res, PrefSum[i]);

        cout << res << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}