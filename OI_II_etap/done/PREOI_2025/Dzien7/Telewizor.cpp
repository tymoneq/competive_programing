#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    static const ll INF = 1e9 + 10;

    int N, M;
    ll res = INF;

    vector<pair<int, int>> Filmy;
    vector<vector<int>> PrefSum;

public:
    inline void read_data()
    {
        cin >> N >> M;

        PrefSum.resize(N * M, vector<int>(N));

        FOR(i, N, 0)
        FOR(j, M, 0)
        {
            int a;
            cin >> a;
            Filmy.push_back({a, i});
        }
        sort(Filmy.begin(), Filmy.end());
    }

    inline bool valid(ll days)
    {
        bool corect = true;

        FOR(i, N * M, 0)
        {
            ll last_day = Filmy[i].first + days;
        }

        return corect;
    }

    inline void solve()
    {
        read_data();

        FOR(i, N, 0)
        {
            if (Filmy[0].second == i)
                PrefSum[0][i] = 1;
            else
                PrefSum[0][i] = 0;

            FOR(j, N * M, 1)
            PrefSum[j][i] = PrefSum[j - 1][i] + (Filmy[j].second == i ? 1 : 0);
        }

        ll lo = 1, hi = INF, mid;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (valid(mid))
            {
                res = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
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