#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
constexpr int N = 2e5 + 10;
vector<int> Tree[N];
int Depth[N];
int Parent[N];
int HowManyOn[N];
int Sto[N];
priority_queue<pair<ll, int>, vector<pair<ll, int>>> pq;

inline void dfs(int v, int parent)
{

    Parent[v] = parent;
    Depth[v] = Depth[parent] + 1;

    for (int w : Tree[v])
        if (w != parent)
        {
            Sto[v]++;
            dfs(w, v);
        }

    if (Tree[v].size() == 1 && v != 1)
        pq.push({Depth[v], v});
}

inline ll calcRes(int k)
{
    ll res = 0;

    while (k--)
    {
        auto v = pq.top();
        pq.pop();

        res += v.first;
        HowManyOn[v.second]++;
        HowManyOn[Parent[v.second]] += HowManyOn[v.second];
        Sto[Parent[v.second]]--;

        if (Sto[Parent[v.second]] == 0)
            pq.push({Depth[Parent[v.second]] - HowManyOn[Parent[v.second]], Parent[v.second]});
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    Depth[1] = -1;
    dfs(1, 1);

    cout << calcRes(k) << "\n";
    return 0;
}