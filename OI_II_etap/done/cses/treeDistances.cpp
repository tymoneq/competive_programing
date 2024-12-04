#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

constexpr int BASE = 1 << 19, N = 2e5 + 10;
int TREE[BASE << 1], LAZY[BASE << 1], Ans[N];
vector<int> adj[N], PrePost, Dist;

// hashing
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash
{
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, pair<int, int>, chash> Ranges;

// map<int, pair<int, int>> Ranges;

inline void add(int v, int poczZapytania, int koniecZapytania, int val, int poczV, int koniecV)
{
    if (poczZapytania > koniecV || koniecZapytania < poczV)
        return;

    if (poczZapytania <= poczV && koniecV <= koniecZapytania)
    {
        TREE[v] += val;
        LAZY[v] += val;
        return;
    }

    int l = v * 2, r = v * 2 + 1, mid = (poczV + koniecV) / 2;
    LAZY[l] += LAZY[v];
    LAZY[r] += LAZY[v];

    TREE[l] += LAZY[v];
    TREE[r] += LAZY[v];

    LAZY[v] = 0;

    add(l, poczZapytania, koniecZapytania, val, poczV, mid);
    add(r, poczZapytania, koniecZapytania, val, mid + 1, koniecV);

    TREE[v] = max(TREE[l], TREE[r]);
}

inline void dfs(int v, int p, int d)
{
    PrePost.push_back(v);
    Dist[v] = d;
    for (int w : adj[v])
        if (w != p)
            dfs(w, v, d + 1);

    PrePost.push_back(v);
}

inline void rerooting(int v, int p)
{
    Ans[v] = TREE[1];

    for (int w : adj[v])
        if (w != p)
        {
            // reroot i rekurencja
            int pocz = Ranges[w].first, koniec = Ranges[w].second;

            add(1, 0, pocz, 1, 0, BASE - 1);
            add(1, pocz, koniec, -1, 0, BASE - 1);
            add(1, koniec, BASE - 1, 1, 0, BASE - 1);
            rerooting(w, v);
        }

    if (v == p)
        return;

    // ponowny reroot

    int pocz = Ranges[v].first, koniec = Ranges[v].second;

    add(1, 0, pocz, -1, 0, BASE - 1);
    add(1, pocz, koniec, 1, 0, BASE - 1);
    add(1, koniec, BASE - 1, -1, 0, BASE - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    Dist.resize(n + 1);

    for (int i = 1; i < n; i++)
    {
        int a, b;

        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1, 0);

    // creating SegmentTree
    for (unsigned int i = 1; i < PrePost.size(); i++)
    {
        if (Ranges[PrePost[i]].first == 0)
        {
            TREE[i + BASE] = Dist[PrePost[i]];
            Ranges[PrePost[i]].first = i;
        }
        else
            Ranges[PrePost[i]].second = i;
    }

    for (int i = BASE - 1; i > 0; i--)
        TREE[i] = max(TREE[i * 2], TREE[i * 2 + 1]);

    rerooting(1, 1);

    for (int i = 1; i <= n; i++)
        cout << Ans[i] << ' ';

    cout << '\n';
    return 0;
}