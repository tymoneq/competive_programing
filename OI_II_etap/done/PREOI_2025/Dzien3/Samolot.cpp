#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;
#warning changee basee 1 <<18
constexpr int base = 1 << 3;

ll SegmentTree[base << 1];

int DrzewoID[base << 1];
int DrzewoMN[base << 1];

class Solve
{
protected:
    struct range
    {
        int l, r;
    };

    struct ostatnieWystapiene
    {
        ll poczatek_uzywania;
        int pocz, koniec;
    };

    const int INF = 1e9 + 5;

    int N, M, Q;
    map<ll, int> WartosciBezpieczenstwa;

    vector<range> Przedzial;
    ll timer = 0;
    vector<ll> Zapytania; // index na drzewie

    vector<ostatnieWystapiene> IdPrzedzialu;

public:
    inline void read_data()
    {
        cin >> N >> M >> Q;

        Przedzial.resize(M + 1);
        Zapytania.resize(Q);
        IdPrzedzialu.resize(M + 1);

        FOR(i, M + 1, 1)
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

        FOR(i, base + base, 0)
        DrzewoMN[i] = INF;
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

    inline void upt_max(int v)
    {
        v += base;
        const int V = v;
        int mx = 0;

        while (v != 0)
        {
            mx = max(mx, DrzewoID[v]);
            v /= 2;
        }

        DrzewoID[V] = mx;
    }

    inline void upt_mn(int v)
    {
        v += base;
        const int V = v;
        int mn = INF;

        while (v != 0)
        {
            mn = min(mn, DrzewoMN[v]);
            v /= 2;
        }

        DrzewoMN[V] = mn;
    }

    inline int querry_mx(int l, int r)
    {
        l += base;
        l--;
        r += base;
        r++;

        int mx = 0;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                mx = max(mx, DrzewoID[l + 1]);

            if (r % 2 == 1)
                mx = max(mx, DrzewoID[r - 1]);

            l /= 2, r /= 2;
        }

        while (l != 0)
        {
            mx = max(mx, DrzewoID[l]);
            l /= 2;
        }

        return mx;
    }

    inline int querry_mn(int l, int r)
    {
        l += base;
        l--;
        r += base;
        r++;

        int mn = INF;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                mn = min(mn, DrzewoMN[l + 1]);

            if (r % 2 == 1)
                mn = min(mn, DrzewoMN[r - 1]);

            l /= 2, r /= 2;
        }
        while (l != 0)
        {
            mn = min(mn, DrzewoMN[l]);
            l /= 2;
        }

        return mn;
    }

    inline void add_mx(int l, int r, int val)
    {
        l += base - 1;
        r += base + 1;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                DrzewoID[l + 1] = val;

            if (r % 2 == 1)
                DrzewoID[r - 1] = val;

            r /= 2, l /= 2;
        }
    }

    inline void add_mn(int l, int r, int val)
    {
        l += base - 1;
        r += base + 1;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                DrzewoMN[l + 1] = val;

            if (r % 2 == 1)
                DrzewoMN[r - 1] = val;

            r /= 2, l /= 2;
        }
    }

    inline void solve()
    {

        read_data();

        FOR(i, M + 1, 1)
        {
            const int pocz = Przedzial[i].l, koniec = Przedzial[i].r;
            timer++;

            IdPrzedzialu[i].pocz = pocz;
            IdPrzedzialu[i].koniec = koniec;
            IdPrzedzialu[i].poczatek_uzywania = timer;

            int l, r, mid, l_bs;
            l = pocz;

            while (l <= koniec)
            {
                upt_max(l);
                upt_mn(l);
                r = koniec;
                l_bs = l;

                int ans = l;

                while (l_bs <= r)
                {
                    mid = l_bs + (r - l_bs) / 2;

                    int mx = querry_mx(l, mid);
                    int mn = querry_mn(l, mid);

                    if (mx == DrzewoID[l + base] && (mx == mn || mn == INF))
                    {
                        ans = mid;
                        l_bs = mid + 1;
                    }

                    else
                        r = mid - 1;
                }

                if (DrzewoID[l + base] != 0)
                {
                    ll czas_odwiedzenia = IdPrzedzialu[DrzewoID[l + base]].poczatek_uzywania + (l - IdPrzedzialu[DrzewoID[l + base]].pocz);
                    ll czas_ponownego_odwiedzenia = timer + (l - pocz);

                    ll diff_time = czas_ponownego_odwiedzenia - czas_odwiedzenia;

                    auto it = WartosciBezpieczenstwa.upper_bound(diff_time);

                    int id = 0;
                    if (it != WartosciBezpieczenstwa.end())
                        id = it->second;
                    else
                        id = base - 1;

                    add(id, ans - l + 1);
                }

                l = ans + 1;
            }

            timer += koniec - pocz;

            // dodaj max i min

            add_mx(pocz, koniec, i);

            add_mn(pocz, koniec, i);
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