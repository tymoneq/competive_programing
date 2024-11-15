#include <bits/stdc++.h>

using namespace std;

constexpr int base = 1 << 19;

int SegmentTree[base << 1];

inline void upt(int v, int val)
{
    v += base;
    SegmentTree[v] = max(SegmentTree[v], val);
    v /= 2;

    while (v > 0)
    {
        SegmentTree[v] = max(SegmentTree[v * 2], SegmentTree[v * 2 + 1]);
        v /= 2;
    }
}

inline int querry(int r)
{
    r += base;
    int l = base;

    int ansMX = 0;
    while (r / 2 != l / 2)
    {
        if (r % 2 == 1)
            ansMX = max(ansMX, SegmentTree[r - 1]);

        if (l % 2 == 0)
            ansMX = max(ansMX, SegmentTree[l + 1]);

        l /= 2, r /= 2;
    }

    return ansMX;
}

inline void solve()
{
    int n;
    cin >> n;

    vector<int> Val(n + 1), ans(n + 1), PrefSum(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> Val[i];

    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, Val[i]);
        PrefSum[i] = mx;
    }

    for (int i = n; i > 0; i--)
    {
        mx = max({PrefSum[i], querry(Val[i]), querry(PrefSum[i])});
        upt(Val[i], mx);
        ans[i] = mx;
    }

    for (int i = 1; i <= n; i++)
        SegmentTree[i + base] = 0;

    for (int i = 1; i <= n; i++)
        upt(i, 0);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    cout << "\n";
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