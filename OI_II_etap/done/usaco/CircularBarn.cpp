#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    int N;
    ll res = 0;
    vector<int> Krowy;
    vector<int> Pokoje;

public:
    inline void read_data()
    {
        cin >> N;
        Krowy.resize(N + 1);

        FOR(i, N + 1, 1)
        cin >> Krowy[i];

        FOR(k, 2, 0)
        for (int i = N; i > 0; i--)
            Pokoje.push_back(i);
    }

    inline void solve()
    {
        read_data();

        FOR(i, Pokoje.size(), 0)
        {
            if (Krowy[Pokoje[i]] > 0)
                continue;

            ll kroki = 0;
            FOR(j, Pokoje.size(), i + 1)
            {
                kroki++;
                if (Krowy[Pokoje[j]] > 0)
                {
                    Krowy[Pokoje[j]]--;
                    Krowy[Pokoje[i]]++;
                    res += kroki * kroki;
                    break;
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

    // freopen("cbarn.in", "r", stdin);
    // freopen("cbarn.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}