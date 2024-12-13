#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

constexpr int N = 2e5 + 10, BASE = 1 << 19;

ll Tree[BASE << 1], Val[N];
vector<int> adj[N];
vector<int> PrePost;
pair<int, int> PrePostIndx[N];

inline void dfs(int v, int p)
{
    PrePost.push_back(v);

    for (int w : adj[v])
        if (w != p)
            dfs(w, v);

    PrePost.push_back(v);
    return;
}

inline void upt(int v, int val)
{
    Tree[v] = val;
    v /= 2;
    while (v > 0)
    {
        Tree[v] = Tree[v * 2] + Tree[v * 2 + 1];
        v /= 2;
    }
    return;
}

inline ll query(int l, int r)
{
    l -= 1, r += 1;
    ll sum = 0;

    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            sum += Tree[l + 1];

        if (r % 2 == 1)
            sum += Tree[r - 1];
        l /= 2, r /= 2;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> Val[i];

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);

    for (unsigned int i = 0; i < PrePost.size(); i++)
    {
        if (PrePostIndx[PrePost[i]].first == 0)
        {
            PrePostIndx[PrePost[i]].first = i + 1 + BASE;
            Tree[BASE + i + 1] += Val[PrePost[i]];
        }
        else
        {

            PrePostIndx[PrePost[i]].second = i + 1 + BASE;
            Tree[BASE + i + 1] -= Val[PrePost[i]];
        }
    }

    for (int i = BASE - 1; i > 0; i--)
        Tree[i] = Tree[i * 2] + Tree[i * 2 + 1];

    while (q--)
    {
        int type, node, x;
        cin >> type >> node;

        if (type == 1)
        {
            cin >> x;

            int Begining = PrePostIndx[node].first;
            int End = PrePostIndx[node].second;

            upt(Begining, x);
            upt(End, -x);
        }
        else
        {
            int Range = PrePostIndx[node].first;

            cout << query(1, Range) << '\n';
        }
    }

    return 0;
}