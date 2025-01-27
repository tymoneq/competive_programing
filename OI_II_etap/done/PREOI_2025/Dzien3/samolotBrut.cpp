#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

constexpr int base = 1 << 18;

ll SegmentTree[base << 1];

class Solve
{
protected:
    struct range
    {
        int l, r;
    };

    int N, M, Q;
    map<ll, int> WartosciBezpieczenstwa;

    vector<ll> Last_time_used;
    vector<range> Przedzial;
    ll timer = 0;
    vector<ll> Zapytania; // index na drzewie

public:
    inline void read_data()
    {
        cin >> N >> M >> Q;

        Last_time_used.resize(N + 1);
        Przedzial.resize(M);
        Zapytania.resize(Q);

        FOR(i, M, 0)
        cin >> Przedzial[i].l >> Przedzial[i].r;

        FOR(i, Q, 0)
        {
            cin >> Zapytania[i];
            WartosciBezpieczenstwa[Zapytania[i]] = 0;
        }

        int cnt = 1;
        for (auto &w : WartosciBezpieczenstwa)
        {
            w.second = cnt;
            cnt++;
        }
    }
    inline void add(int r)
    {
        int l = base;
        r += base;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                SegmentTree[l + 1]++;

            if (r % 2 == 1)
                SegmentTree[r - 1]++;

            l /= 2, r /= 2;
        }
    }

    inline ll calc_sum(int v)
    {
        v += base;
        ll sum = SegmentTree[v];
        v /= 2;

        while (v != 0)
        {
            sum += SegmentTree[v];
            v /= 2;
        }

        return sum;
    }

    inline void solve()
    {

        read_data();

        for (auto przed : Przedzial)
            FOR(i, przed.r + 1, przed.l)
            {
                timer++;
                if (Last_time_used[i] == 0)
                    Last_time_used[i] = timer;

                else
                {
                    ll time_difference = timer - Last_time_used[i] - 1;
                    Last_time_used[i] = timer;

                    auto it = WartosciBezpieczenstwa.upper_bound(time_difference);

                    int id = 0;
                    if (it != WartosciBezpieczenstwa.end())
                        id = it->second;
                    else
                        id = base - 1;

                    add(id);
                }
            }

        FOR(i, Q, 0)
        {
            int id = WartosciBezpieczenstwa[Zapytania[i]];

            cout << calc_sum(id) << ' ';
        }

        cout << '\n';
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