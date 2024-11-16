#include <bits/stdc++.h>

using namespace std;

constexpr int K = 447, N = 1e6 + 10;

struct Querry
{
    int l, r, indx;
};
int cnt[N];

inline bool SortQuerry(Querry &lhs, Querry &rhs)
{
    if (lhs.l / K == rhs.l / K)
        return lhs.r < rhs.r;
    return lhs.l / K < rhs.l / K;
}

inline void dodaj(int indx, int &odd, vector<int> &Targets)
{
    cnt[Targets[indx]]++;
    if (cnt[Targets[indx]] % 2 == 0)
        odd--;
    else
        odd++;
}

inline void odejmij(int indx, int &odd, vector<int> &Targets)
{
    cnt[Targets[indx]]--;
    if (cnt[Targets[indx]] % 2 == 0)
        odd--;
    else
        odd++;
}

inline void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> Targets(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> Targets[i];

    vector<Querry> Q(q);

    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].indx = i;
    }

    sort(Q.begin(), Q.end(), SortQuerry);

    vector<bool> Ans(q);

    int odd = 0;
    int l = 1, r = 0;

    for (auto querry : Q)
    {
        while (r < querry.r)
        {
            r++;
            dodaj(r, odd, Targets);
        }
        while (r > querry.r)
        {
            odejmij(r, odd, Targets);
            r--;
        }

        while (l > querry.l)
        {
            l--;
            dodaj(l, odd, Targets);
        }
        while (l < querry.l)
        {

            odejmij(l, odd, Targets);
            l++;
        }

        if (odd == 0)
            Ans[querry.indx] = 1;
    }

    for (int i = 0; i < q; i++)
        cout << (Ans[i] ? "YES" : "NO") << '\n';

    while (l <= n)
    {
        cnt[Targets[l]] = 0;
        l++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}