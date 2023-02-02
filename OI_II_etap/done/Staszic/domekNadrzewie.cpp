#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 20, base = 1 << 15;
struct Querry
{
    ll t, k, i;
};
vector<int> adj[M];
bool IsFactory[M];
int Count[M];
int Tree[base << 1];
vector<Querry> Q[M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b, x;
    ll m, k, t;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        IsFactory[i] = a;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (IsFactory[i])
            Count[i]++;
        for (int w : adj[i])
            if (IsFactory[w])
                Count[i]++;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x >> t >> k;
        Q[x].push_back({t, k, i});
    }
    return 0;
}