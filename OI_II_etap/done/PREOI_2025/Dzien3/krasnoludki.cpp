#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

constexpr int base = 1 << 17;

struct node
{
    int ile_w_prawo = 0;
    int ile_w_lewo = 0;

    int lazy_ile_w_prawo = 0;
    int lazy_ile_w_lewo = 0;
};

node SegmentTree[base << 1];

class Solve
{
protected:
    int N, M, Q;
    vector<int> Krasnoludek;
    vector<char> Tabliczki;

public:
    inline void read_data()
    {
        cin >> N >> M >> Q;

        Krasnoludek.resize(M + 1);
        Tabliczki.resize(N + 1);

        FOR(i, N + 1, 1)
        cin >> Tabliczki[i];

        FOR(i, M + 1, 1)
        cin >> Krasnoludek[i];
    }

    inline void set_tree()
    {
        FOR(i, N + 1, 1)
        {
            SegmentTree[i + base] = {0, 0, 0, 0};

            if (Tabliczki[i] == '<')
                SegmentTree[i + base].ile_w_lewo = 1;

            else
                SegmentTree[i + base].ile_w_prawo = 1;
        }

        for (int i = base - 1; i > 0; i--)
        {
            SegmentTree[i] = {0, 0, 0, 0};
            SegmentTree[i].ile_w_prawo = SegmentTree[i * 2].ile_w_prawo + SegmentTree[i * 2 + 1].ile_w_prawo;
            SegmentTree[i].ile_w_lewo = SegmentTree[i * 2].ile_w_lewo + SegmentTree[i * 2 + 1].ile_w_lewo;
        }
    }

    inline void upt(int v)
    {
        v /= 2;

        while (v > 0)
        {
            SegmentTree[v].ile_w_prawo = SegmentTree[v * 2].ile_w_prawo + SegmentTree[v * 2 + 1].ile_w_prawo;
            SegmentTree[v].ile_w_lewo = SegmentTree[v * 2].ile_w_lewo + SegmentTree[v * 2 + 1].ile_w_lewo;
            v /= 2;
        }
    }

    inline void calc_ans(int l, int r)
    {
        FOR(krasnal, r + 1, l)
        {
            SegmentTree[Krasnoludek[krasnal] + base] = {0, 0, 0, 0};
            SegmentTree[Krasnoludek[krasnal] + base].ile_w_prawo = 1;

            upt(Krasnoludek[krasnal] + base);

            
        }
    }

    inline void solve()
    {
        read_data();

        while (Q--)
        {
            set_tree();

            int l, r;
            cin >> l >> r;

            calc_ans(l, r);

            cout << SegmentTree[1].ile_w_prawo << '\n';
        }
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