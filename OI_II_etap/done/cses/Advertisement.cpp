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
    stack<pair<ll, ll>> AktualnePlakaty;
    vector<ll> Plakaty;

public:
    inline void solve()
    {
        cin >> N;
        Plakaty.resize(N);

        FOR(i, N, 0)
        cin >> Plakaty[i];

        FOR(i, N, 0)
        {
            res = max(res, Plakaty[i]);
            pair<ll, ll> AktualnyPlakat = {Plakaty[i], 1};
            ll ile_dodac = 0;

            while (!AktualnePlakaty.empty() && AktualnePlakaty.top().first >= Plakaty[i])
            {
                AktualnyPlakat.second += AktualnePlakaty.top().second;
                res = max(res, AktualnePlakaty.top().first * (AktualnePlakaty.top().second + ile_dodac));

                ile_dodac += AktualnePlakaty.top().second;
                AktualnePlakaty.pop();
            }

            res = max(res, AktualnyPlakat.first * AktualnyPlakat.second);

            AktualnePlakaty.push(AktualnyPlakat);
        }

        ll ile_dodac = 0;

        while (!AktualnePlakaty.empty())
        {
            res = max(res, AktualnePlakaty.top().first * (AktualnePlakaty.top().second + ile_dodac));
            ile_dodac += AktualnePlakaty.top().second;
            AktualnePlakaty.pop();
        }

        cout << res << '\n';
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