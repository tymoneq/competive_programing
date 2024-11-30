#include <bits/stdc++.h>

using namespace std;
struct points
{
    int R, C, L, indx;
};

constexpr int N = 2e5 + 10, base = 1 << 18;
int ANS[N];

inline bool sortPoints(const points &lhs, const points &rhs)
{
    if (lhs.R == rhs.R)
        return lhs.C < rhs.C;

    return lhs.R > rhs.R;
}

int SegmentTree[base << 1], Lazy[base << 1];

inline void query(int v, int p, int k, int poczV, int koniecV, int &ans)
{
    if (k < poczV || koniecV < p)
        return;

    if (p <= poczV && koniecV <= k)
    {
        ans = min(SegmentTree[v], ans);
        return;
    }

    int l = v * 2, r = l + 1, mid = (poczV + koniecV) / 2;

    SegmentTree[l] = min(SegmentTree[l], Lazy[v]);
    SegmentTree[r] = min(SegmentTree[r], Lazy[v]);
    Lazy[l] = min(Lazy[l], Lazy[v]);
    Lazy[r] = min(Lazy[r], Lazy[v]);

    Lazy[v] = numeric_limits<int>::max();

    query(l, p, k, poczV, mid, ans);
    query(r, p, k, mid + 1, koniecV, ans);

    SegmentTree[v] = min(SegmentTree[l], SegmentTree[r]);
}

inline void changeMin(int v, int p, int k, int val, int poczV, int koniecV)
{
    if (k < poczV || koniecV < p)
    {
        return;
    }
    if (p <= poczV && koniecV <= k)
    {
        SegmentTree[v] = min(val, SegmentTree[v]);
        Lazy[v] = min(Lazy[v], val);
        return;
    }

    int l = v * 2, r = l + 1, mid = (poczV + koniecV) / 2;

    // SegmentTree[l] = min(val, Lazy[v]);
    // SegmentTree[r] = min(val, Lazy[v]);
    // Lazy[l] = min(val, Lazy[v]);
    // Lazy[r] = min(val, Lazy[v]);

    // Lazy[v] = numeric_limits<int>::max();

    changeMin(l, p, k, val, poczV, mid);
    changeMin(r, p, k, val, mid + 1, koniecV);

    SegmentTree[v] = min(SegmentTree[l], SegmentTree[r]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int H, W, n;
    cin >> H >> W >> n;

    vector<points> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].R >> A[i].C >> A[i].L;
        A[i].indx = i;
    }

    for (int i = base; i < base * 2; i++)
    {
        SegmentTree[i] = H;
        Lazy[i] = H;
    }

    for (int i = base - 1; i > 0; i--)
    {
        SegmentTree[i] = H;
        Lazy[i] = H;
    }

    sort(A.begin(), A.end(), sortPoints);

    int firstR = A[0].R;

    for (int i = 0; i < n; i++)
    {
        if (firstR == A[i].R)
        {
            ANS[A[i].indx] = H;
            // dodaj na przedziale
            changeMin(1, A[i].C, A[i].C + A[i].L - 1, H - 1, 1, base);
        }
        else
        {

            // zapytaj się o min na przedziale
            int ans = numeric_limits<int>::max();
            query(1, A[i].C, A[i].C + A[i].L - 1, 1, base, ans);
            ANS[A[i].indx] = ans;
            // dodaj na przedział
            changeMin(1, A[i].C, A[i].C + A[i].L - 1, ans - 1, 1, base);
        }
    }

    for (int i = 0; i < n; i++)
        cout << ANS[i] << '\n';
    return 0;
}