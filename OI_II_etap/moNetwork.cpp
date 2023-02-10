#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
struct edge
{
    ll weight;
    int start, end;
};

constexpr int M = 1e5+10;
ll val;
int R[M];
inline bool sorto(edge &lhs, edge &rhs) { return lhs.weight < rhs.weight; }
inline int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
int fa, fb;
inline void onion(int a, int b, ll w)
{
    fa = fint(a), fb = fint(b);
    if (fa == fb)
        return;
    R[fa] = fb;
    val += w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> V(n);
    vector<edge> E;
    for (int i = 0; i < n; i++)
    {
        cin >> V[i].first >> V[i].second;
        R[i] = i;
    }
    ll tmp;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            tmp = (V[i].first - V[j].first) * (V[i].first - V[j].first) + (V[i].second - V[j].second) * (V[i].second - V[j].second);
            E.push_back({tmp, i, j});
        }
    sort(E.begin(), E.end(), sorto);
    for (auto w : E)
        onion(w.start, w.end, w.weight);
    cout << val;
    return 0;
}