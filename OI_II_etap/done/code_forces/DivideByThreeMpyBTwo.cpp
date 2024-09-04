#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, vector<ll>> adj;
map<ll, bool> Visited;

void dfs(ll v)
{
    cout << v << " ";

    Visited[v] = 1;
    for (ll w : adj[v])
        if (!Visited[w])
            dfs(w);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll a;

    map<ll, ll> M;
    cin >> n;
    vector<ll> V(n);
    for (auto &el : V)
    {
        cin >> el;
        M[el]++;
    }
    for (auto el : V)
    {
        if (M[el * (ll)2] != 0)
        {
            adj[el].push_back(el * (ll)2);
            adj[el * 2].push_back(el);
        }
        if (el % 3 == 0 && M[el / (ll)3] != 0)
        {
            adj[el].push_back(el / (ll)3);
            adj[el / 3].push_back(el);
        }
    }

    ll r = 0;
    for (auto e : adj)
        if (e.second.size() == 1 && (M[e.first / 3] > 0 || M[e.first * 2] > 0))
        {
            r = e.first;
            break;
        }

    dfs(r);

    cout << "\n";
    return 0;
}