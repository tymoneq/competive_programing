#include <bits/stdc++.h>

using namespace std;

constexpr int base = 1 << 18;

unordered_map<int, int> SegmentTree[base << 1];

inline void upt2(int v)
{
    v /= 2;
    while (v > 0)
    {
        SegmentTree[v].clear();
        v /= 2;
    }
}
inline bool querry(int l, int r)
{
    unordered_map<int, int> A;
    l += base, r += base;
    l--, r++;

    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            for (auto el : SegmentTree[l + 1])
                A[el.first] += el.second;

        if (r % 2 == 1)
            for (auto el : SegmentTree[r - 1])
                A[el.first] += el.second;

        r /= 2, l /= 2;
    }

    bool Valid = 1;
    for (auto el : A)
        if (el.second % 2 == 1)
        {
            Valid = 0;
            break;
        }

    return Valid;
}

inline void solve()
{

    int n, q;
    cin >> n >> q;
    queue<int> Q;
    set<int> Used;

    for (int i = base + 1; i <= base + n; i++)
    {
        int a;
        cin >> a;
        SegmentTree[i][a]++;
        Q.push(i);
    }

    // updating segment Tree
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();

        for (auto el : SegmentTree[v])
            SegmentTree[v / 2][el.first] += el.second;

        if (v / 2 != 1 && !Used.count(v / 2))
        {
            Q.push(v / 2);
            Used.insert(v / 2);
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if ((r - l + 1) % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }

        if (querry(l, r))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    // clearing segment tree
    for (int i = base + 1; i <= base + n; i++)
        SegmentTree[i].clear();

    for (int i = base + 1; i <= base + n; i++)
        upt2(i);
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