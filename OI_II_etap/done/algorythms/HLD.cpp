#include <bits/stdc++.h>

using namespace std;

// #pragma message("CHANGE MAXN TO 1E4+10 AND BASE 1 << 14")
constexpr int MAXN = 1e4+10;
constexpr int Base = 1 << 14;

int Parent[MAXN], Depth[MAXN], Heavy[MAXN], Head[MAXN], Pos[MAXN];
int cur_pos;
int Tree[Base << 1];
vector<int> adj[MAXN];
int EDGE[MAXN];

int dfs(int v)
{
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v])
        if (c != Parent[v])
        {
            Parent[c] = v, Depth[c] = Depth[v] + 1;
            int c_size = dfs(c);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, Heavy[v] = c;
        }

    return size;
}

void decompose(int v, int h)
{
    Head[v] = h, Pos[v] = cur_pos++;
    if (Heavy[v] != -1)
        decompose(Heavy[v], h);

    for (int c : adj[v])
        if (c != Parent[v] && c != Heavy[v])
            decompose(c, c);
}

void upt(int v)
{
    Tree[Base + Pos[v + 1] + 1] = EDGE[v];
    int w = Base + Pos[v + 1];
    w /= 2;
    while (w > 0)
    {
        Tree[w] = max(Tree[w * 2], Tree[w * 2 + 1]);
        w /= 2;
    }
}

int segment_tree_query(int a, int b)
{
    int l = a + Base, r = b + Base + 2;
    int max_in_range = -1;
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            max_in_range = max(max_in_range, Tree[l + 1]);
        if (r % 2 == 1)
            max_in_range = max(max_in_range, Tree[r - 1]);

        l /= 2, r /= 2;
    }
    return max_in_range;
}

int query(int a, int b)
{
    int res = 0;
    for (; Head[a] != Head[b]; b = Parent[Head[b]])
    {
        if (Depth[Head[a]] > Depth[Head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment_tree_query(Pos[Head[b]], Pos[b]);
        res = max(res, cur_heavy_path_max);
    }

    if (Depth[a] > Depth[b])
        swap(a, b);
    int last_heavy_path_max = segment_tree_query(Pos[Head[b]], Pos[b]);
    res = max(res, last_heavy_path_max);

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, a, b, c;
    string s;
    cin >> t;

    while (t--)
    {
        // cleaning tables
        cur_pos = 0;
        for (int i = 0; i < MAXN; i++)
        {
            Parent[i] = 0, Depth[i] = 0, Heavy[i] = -1, Head[i] = 0, Pos[i] = 0;
            adj[i].clear();
        }

        cin >> n;

        // reading data and making tree
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b >> c;
            adj[a].push_back(b);
            adj[b].push_back(a);
            EDGE[i + 1] = c;
        }

        dfs(1);
        decompose(1, 1);

        // creating seqment tree

        Tree[Base + 1] = -1;
        for (int i = 2; i <= n; i++)
            Tree[Base + Pos[i] + 1] = EDGE[i - 1];

        for (int i = Base - 1; i > 0; i--)
            Tree[i] = max(Tree[i * 2], Tree[2 * i + 1]);

        while (1)
        {
            cin >> s;
            if (s == "DONE")
                break;

            cin >> a >> b;
            if (s == "QUERY")
                cout << query(a, b) << "\n";

            else if (s == "CHANGE")
            {
                EDGE[a] = b;
                upt(a);
            }
        }

        cout << "\n";
    }

    return 0;
}