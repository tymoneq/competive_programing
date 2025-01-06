#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    const int INF = 1e9 + 5;
    int N, B;
    vector<pair<int, int>> Buty;
    vector<int> Snieg;
    vector<vector<int>> Wynik;

public:
    inline void read_data()
    {
        cin >> N >> B;

        Snieg.resize(N + 1);
        Wynik.resize(N + 1);

        Buty.resize(B);

        FOR(i, N + 1, 1)
        cin >> Snieg[i];

        FOR(i, B, 0)
        cin >> Buty[i].first >> Buty[i].second;

        FOR(i, N + 1, 0)
        Wynik[i].resize(B + 1, INF);
    }

    inline void solve()
    {
        read_data();
        FOR(i, B, 0)
        Wynik[1][i] = i;

        FOR(but, B, 0)
        {
            FOR(i, N + 1, 2)
            {
                if (Snieg[i] > Buty[but].first)
                    continue;

                int mn = INF;

                for (int skok = 1; skok <= Buty[but].second; skok++)
                {
                    if (i - skok < 1)
                        break;

                    if (Snieg[i - skok] > Buty[but].first)
                        continue;

                    mn = min(mn, Wynik[i - skok][but]);

                    FOR(k, but, 0)
                    mn = min(mn, Wynik[i - skok][k] + (but - k));
                }

                Wynik[i][but] = mn;
            }
        }

        int res = INF;
        FOR(i, B, 0)
        res = min(res, Wynik[N][i]);

        cout << res << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}