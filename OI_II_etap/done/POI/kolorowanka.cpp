#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 10, base = 1 << 19;

typedef long long ll;

vector<int> adj[N];
int Parent[N], Sajz[N];
bool secondCentroid;

vector<int> SegmentTree1, SegmentTree2, depth1, depth2, SegmentTreeA1, SegmentTreeA2;

inline void dfs3(int v, int p)
{
    depth2[v] = depth2[p] + 1;
    for (int w : adj[v])
        if (w != p)
            dfs3(w, v);
}

inline void dfs2(int v, int p)
{
    depth1[v] = depth1[p] + 1;
    for (int w : adj[v])
        if (w != p)
            dfs2(w, v);
}

inline void dfs1(int v, int p)
{

    Sajz[v] = 1;
    Parent[v] = p;
    for (int w : adj[v])
        if (w != p)
        {
            dfs1(w, v);
            Sajz[v] += Sajz[w];
        }
}

inline int findCentroid(int v, int tree_sajz)
{
    for (int w : adj[v])
    {
        if (w == Parent[v] && tree_sajz - Sajz[v] > ((tree_sajz) / 2))
            return findCentroid(Parent[v], tree_sajz);
        else if (w != Parent[v] && Sajz[w] > (((tree_sajz) / 2)))
            return findCentroid(w, tree_sajz);
    }

    return v;
}
inline int checkSecondCentroid(int v, int tree_sajz)
{

    int ans = -1;
    for (int w : adj[v])
    {
        if (w == Parent[v] && tree_sajz - Sajz[v] >= ((tree_sajz + 1) / 2))
            ans = w;
        else if (w != Parent[v] && Sajz[w] >= (((tree_sajz + 1) / 2)))
            ans = w;
    }

    return ans;
}

inline void calc(int n)
{
    dfs1(1, 0);
    int centroid = findCentroid(1, n);
    int centroid2 = checkSecondCentroid(centroid, n);

    depth1.resize(n + 1), depth2.resize(n + 1);

    dfs2(centroid, centroid);

    if (centroid2 != -1)
    {
        secondCentroid = 1;
        dfs3(centroid2, centroid2);
    }
}

inline void uptSegment1(int v, int val)
{
    v += base;
    SegmentTree1[v] += val;

    v /= 2;
    while (v > 0)
    {
        SegmentTree1[v] = SegmentTree1[v * 2] + SegmentTree1[v * 2 + 1];
        v /= 2;
    }
}

inline ll querrySegment1(int l)
{
    l += base - 1;
    ll sum = 0;
    int r = (base << 1) - 1;
    while (r / 2 != l / 2)
    {
        if (l % 2 == 0)
            sum += SegmentTree1[l + 1];
        if (r % 2 == 1)
            sum += SegmentTree1[r - 1];
        l /= 2, r /= 2;
    }

    return sum;
}

inline void uptSegment2(int v, int val)
{
    v += base;
    SegmentTree2[v] += val;

    v /= 2;
    while (v > 0)
    {
        SegmentTree2[v] = SegmentTree2[v * 2] + SegmentTree2[v * 2 + 1];
        v /= 2;
    }
}

inline ll querrySegment2(int l)
{
    l += base - 1;
    ll sum = 0;
    int r = (base << 1) - 1;
    while (r / 2 != l / 2)
    {
        if (l % 2 == 0)
            sum += SegmentTree2[l + 1];
        if (r % 2 == 1)
            sum += SegmentTree2[r - 1];
        l /= 2, r /= 2;
    }

    return sum;
}

inline ll querrySegmentA1(int r)
{
    ll sum = 0;
    r += base + 1;
    int l = base;

    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            sum += SegmentTreeA1[l + 1];
        if (r % 2 == 1)
            sum += SegmentTreeA1[r - 1];
        r /= 2, l /= 2;
    }
    return sum;
}

inline ll querrySegmentA2(int r)
{
    ll sum = 0;
    r += base + 1;
    int l = base;

    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            sum += SegmentTreeA2[l + 1];
        if (r % 2 == 1)
            sum += SegmentTreeA2[r - 1];
        r /= 2, l /= 2;
    }
    return sum;
}

inline void uptSegmentA1(int v, int val)
{
    v += base;
    SegmentTreeA1[v] += val;
    v /= 2;
    while (v > 0)
    {
        SegmentTreeA1[v] = SegmentTreeA1[v * 2] + SegmentTreeA1[v * 2 + 1];
        v /= 2;
    }
}

inline void uptSegmentA2(int v, int val)
{
    v += base;
    SegmentTreeA2[v] += val;
    v /= 2;
    while (v > 0)
    {
        SegmentTreeA2[v] = SegmentTreeA2[v * 2] + SegmentTreeA2[v * 2 + 1];
        v /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    secondCentroid = 0;
    int n, q, e, d, A, B;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> e >> d;
        adj[e].push_back(d);
        adj[d].push_back(e);
    }

    calc(n);
    cin >> A >> B >> q;
    set<int> zbiorA, zbiorB;

    SegmentTree1.resize(base << 1);
    SegmentTree2.resize(base << 1);
    SegmentTreeA1.resize(base << 1);
    SegmentTreeA2.resize(base << 1);

    for (int i = 0; i < A; i++)
    {
        int a;
        cin >> a;
        zbiorA.insert(a);
    }

    for (int i = 0; i < B; i++)
    {
        int b;
        cin >> b;
        zbiorB.insert(b);

        uptSegment1(depth1[b], 1);
        uptSegment2(depth2[b], 1);
    }
    ll res = 0;
    for (int a : zbiorA)
    {
        if (secondCentroid)
            res += min(querrySegment1(depth1[a]), querrySegment2(depth2[a]));

        else
            res += querrySegment1(depth1[a]);

        if (zbiorB.find(a) != zbiorB.end())
            res--;

        SegmentTreeA1[depth1[a] + base]++;
        SegmentTreeA2[depth2[a] + base]++;
    }
    cout << res << "\n";

    // seting values in segment Trees;

    for (int i = base - 1; i > 0; i--)
    {
        SegmentTreeA1[i] = SegmentTreeA1[i * 2] + SegmentTreeA1[i * 2 + 1];
        SegmentTreeA2[i] = SegmentTreeA2[i * 2] + SegmentTreeA2[i * 2 + 1];
    }

    for (int i = 0; i < q; i++)
    {
        char C, znak;
        int val;
        cin >> C >> znak >> val;
        if (C == 'B')
        {
            if (znak == '-')
            {
                uptSegment1(depth1[val], -1);
                uptSegment2(depth2[val], -1);
                zbiorB.erase(val);
                if (zbiorA.find(val) != zbiorA.end())
                    res++;

                if (secondCentroid)
                    res -= min(querrySegmentA1(depth1[val]), querrySegmentA2(depth2[val]));
                else
                    res -= querrySegmentA1(depth1[val]);
            }
            if (znak == '+')
            {
                uptSegment1(depth1[val], 1);
                uptSegment2(depth2[val], 1);
                zbiorB.insert(val);
                if (zbiorA.find(val) != zbiorA.end())
                    res--;
                if (secondCentroid)
                    res += min(querrySegmentA1(depth1[val]), querrySegmentA2(depth2[val]));
                else
                    res += querrySegmentA1(depth1[val]);
            }
        }
        else
        {
            if (znak == '-')
            {
                uptSegmentA1(depth1[val], -1);
                uptSegmentA2(depth2[val], -1);
                zbiorA.erase(val);
                if (zbiorB.find(val) != zbiorB.end())
                    res++;
                if (secondCentroid)
                    res -= min(querrySegment1(depth1[val]), querrySegment2(depth2[val]));
                else
                    res -= querrySegment1(depth1[val]);
            }
            if (znak == '+')
            {
                uptSegmentA1(depth1[val], 1);
                uptSegmentA2(depth2[val], 1);
                zbiorA.insert(val);
                if (zbiorB.find(val) != zbiorB.end())
                    res--;
                if (secondCentroid)
                    res += min(querrySegment1(depth1[val]), querrySegment2(depth2[val]));
                else
                    res += querrySegment1(depth1[val]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}