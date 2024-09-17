#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 2e5 + 10;
constexpr int base = 1 << 15;

struct querry
{
    ll t, k;
    int i;
};

vector<int> adj[N];
vector<querry> Q[N];
int Tree[base << 1], Upgrades[N];
ll ANS[N];
bool Factory[N];
ll m;

void upt(int v)
{
    v /= 2;
    while (v != 0)
    {
        Tree[v] = Tree[v * 2] + Tree[v * 2 + 1];
        v /= 2;
    }
}
int querry_sum(int l)
{
    l -= 1;
    int sum = 0;
    int r = (base << 1) - 2;
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

void dfs(int v, int p)
{
    if (Factory[v])
    {
        Upgrades[v]++;
        for (int w : adj[v])
            Upgrades[w]++;
    }

    for (int w : adj[v])
        if (w != p)
            dfs(w, v);
}

void calc(int v, int p)
{
    // Adding value to seqment tree;
    if (Upgrades[v] != 0)
    {
        Tree[Upgrades[v] + base]++;
        upt(Upgrades[v] + base);
    }
    // calculating querries
    for (auto q : Q[v])
    {
        if (Tree[1] < q.t)
            ANS[q.i] = -1;
        else
        {
            // finding the smallst element
            ll l = base + 1, h = (base << 1) - 2, mid, ans, res = 0;
            while (l <= h)
            {
                mid = l + (h - l) / 2;
                if (querry_sum(mid) >= q.t)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                    h = mid - 1;
            }
            ans -= base;

            l = 0, h = m;
            while (l <= h)
            {
                mid = l + (h - l) / 2;
                if (mid * mid + mid >= ((q.k + (ans - 1)) / ans << 1))
                {
                    res = mid;
                    h = mid - 1;
                }
                else
                    l = mid + 1;
            }
            ANS[q.i] = res;
        }
    }

    // normal dfs
    for (int w : adj[v])
        if (w != p)
            calc(w, v);

    if (Upgrades[v] != 0)
    {
        // Removing value from seqment tree
        Tree[Upgrades[v] + base]--;
        upt(Upgrades[v] + base);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q, a, b, x, t, k;

    cin >> n >> m;
    m = min((ll)1500000000, m);
    for (int i = 1; i <= n; i++)
        cin >> Factory[i];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // Policzenie bazowych poziomów ulepszeń dla każdego wierzchołka
    dfs(1, 0);

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> t >> k;
        Q[x].push_back({t, k, i});
    }
    calc(1, 0);
    for (int i = 0; i < q; i++)
        cout << ANS[i] << "\n";

    return 0;
}