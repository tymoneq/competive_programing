#include <bits/stdc++.h>

using namespace std;
using std::vector;
template <class T>
struct Seg
{
    int n;
    const T ID = 0;
    vector<T> seg;

    T comb(T a, T b)
    {
        return a + b;
    }

    void init(int _n)
    {
        n = _n;
        seg.assign(2 * n, ID);
    }

    void pull(int p)
    {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }

    // update the value at position p
    void upd(int p, T val)
    {
        seg[p += n] = val;

        for (p /= 2; p; p /= 2)
        {
            pull(p);
        }
    }

    // get the sum on the interval [l, r]
    T query(int l, int r)
    {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                ra = comb(ra, seg[l++]);
            if (r & 1)
                rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};
int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    vector<int> Loc(n * 2);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a;
        Loc[i] = --a;
    }
    long long res = 0;
    Seg<int> start_occ;
    start_occ.init(2 * n);
    map<int, int> Starts;
    for (int i = 0; i < n * 2; i++)
    {
        if (Starts.find(Loc[i]) == Starts.end())
        {
            Starts[Loc[i]] = i;
            start_occ.upd(i, 1);
        }
        else
        {
            res += start_occ.query(Starts[Loc[i]] + 1, i - 1);
            start_occ.upd(Starts[Loc[i]], 0);
            Starts.erase(Loc[i]);
        }
    }
    cout << res;
    return 0;
}