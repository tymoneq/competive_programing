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

    struct maszyny
    {
        ll last_time_used;
        int start, koniec;
    };

    struct maszynyComparator
    {
        bool operator()(const maszyny &lhs, const maszyny &rhs) const
        {
            if (lhs.koniec == rhs.koniec)
                return lhs.start < rhs.start;

            return lhs.koniec < rhs.koniec;
        }
    };

    int N, M, Q;
    map<ll, int> WartosciBezpieczenstwa;

    ll Last_time_used = 1;
    vector<range> Przedzial;

    vector<ll> Zapytania; // index na drzewie

    set<maszyny, maszynyComparator> Ranges;

public:
    inline void read_data()
    {
        cin >> N >> M >> Q;

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
    inline void add(int r, int val)
    {
        int l = base;
        r += base;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                SegmentTree[l + 1] += val;

            if (r % 2 == 1)
                SegmentTree[r - 1] += val;

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
        {
            auto it = Ranges.lower_bound({0, 0, przed.l});
            ll timer = Last_time_used;
            int ind = przed.l;

            vector<maszyny> to_erase;
            vector<maszyny> to_add;

            while (it != Ranges.end() && it->start <= przed.r)
            {
                ll tmp_timer = it->last_time_used;

                if (it->start < przed.l)
                    to_add.push_back({it->last_time_used, it->start, przed.l - 1});

                if (it->koniec > przed.r)
                    to_add.push_back({it->last_time_used + (przed.r - it->start + 1), przed.r + 1, it->koniec});

                if (it->start < ind)
                    tmp_timer += ind - it->start;

                if (it->start > ind)
                {
                    timer += it->start - ind;
                    ind = it->start;
                }

                ll time_diff = timer - tmp_timer - 1;

                auto itr = WartosciBezpieczenstwa.upper_bound(time_diff);

                int id = 0;
                if (itr != WartosciBezpieczenstwa.end())
                    id = itr->second;
                else
                    id = base - 1;

                add(id, min(it->koniec, przed.r) - ind + 1);

                timer += min(it->koniec, przed.r) - ind;
                ind = min(it->koniec, przed.r);

                to_erase.push_back(*it);
                it++;
            }

            for (auto w : to_erase)
                Ranges.erase(w);

            for (auto w : to_add)
                Ranges.insert(w);

            // dodaj nowy przedzial
            Ranges.insert({Last_time_used, przed.l, przed.r});
            Last_time_used += przed.r - przed.l + 1;
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