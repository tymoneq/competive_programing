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
    set<int> somsiad;
    vector<int> KolorKorytarza, KolorKluczaNaStart, WymaganyKolorKlucza;
    vector<int> Sciezka;
    map<int, int> Klucze;
    vector<bool> Vis;

public:
    inline void
    read_data()
    {
        cin >> N >> M;

        Graf.resize(N + 1);
        KolorKorytarza.resize(N + 1);
        KolorKluczaNaStart.resize(N + 1);
        WymaganyKolorKlucza.resize(N + 1);
        Vis.resize(N + 1);

        FOR(i, N + 1, 1)
        cin >> KolorKorytarza[i];

        FOR(i, N + 1, 1)
        cin >> KolorKluczaNaStart[i];

        FOR(i, N + 1, 1)
        cin >> WymaganyKolorKlucza[i];

        FOR(i, M, 0)
        {
            int a, b;
            cin >> a >> b;
            Graf[a].push_back(b);
            Graf[b].push_back(a);
        }
    }
    inline void solve()
    {
        read_data();
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        Solve solution;
        solution.solve();
    }

    return 0;
}