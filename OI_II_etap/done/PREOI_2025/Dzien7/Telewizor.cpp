#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

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

    vector<vector<ll>> Filmy;
    set<ll> StartTimes;

public:
    inline void test()
    {

        N = 250, M = 250;
        Filmy.resize(N, vector<ll>(M, 0));

        int num = 0;

        FOR(i, N, 0)
        FOR(j, M, 0)
        {
            num++;
            Filmy[i][j] = num;
            StartTimes.insert(Filmy[i][j]);
        }
        FOR(i, N, 0)
        sort(Filmy[i].begin(), Filmy[i].end());
    }

    inline void read_data()
    {
        cin >> N >> M;

        Filmy.resize(N, vector<ll>(M, 0));

        FOR(i, N, 0)
        FOR(j, M, 0)
        {
            cin >> Filmy[i][j];

            StartTimes.insert(Filmy[i][j]);
        }
        FOR(i, N, 0)
        sort(Filmy[i].begin(), Filmy[i].end());
    }

    inline ll find_id(int i, ll stime)
    {

        ll lo = 0, hi = M - 1, mid, ans = INF * 10000;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (Filmy[i][mid] >= stime)
            {
                ans = Filmy[i][mid];
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return ans;
    }

    inline bool valid(ll days)
    {
        bool corect = true;

        for (ll stime : StartTimes)
        {
            corect = true;
            FOR(i, N, 0)
            {
                ll first_greater_time = find_id(i, stime);

                if (first_greater_time > stime + days - 1)
                {
                    corect = false;
                    break;
                }
            }

            if (corect)
                return true;
        }

        return corect;
    }

    inline void solve()
    {
        read_data();
        // test();

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