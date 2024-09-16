#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// #warning change N = 2e4+10;
constexpr int N = 2e4 + 10;

vector<int> adj[N];
int Parent[N], Upgrades[N];
bool Factory[N];
vector<int> upgrade_path;

void dfs(int v, int p)
{
    Parent[v] = p;
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

void path_counting(int v)
{
    while (v != 0)
    {
        if (Upgrades[v] > 0)
            upgrade_path.push_back(Upgrades[v]);

        v = Parent[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q, a, b, x, t;
    ll m, k;
    cin >> n >> m;
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
        upgrade_path.clear();
        path_counting(x);
        if (t > upgrade_path.size())
            cout << -1 << "\n";
        else
        {
            sort(upgrade_path.begin(), upgrade_path.end(), greater<int>());
            a = upgrade_path[t - 1];
            ll l = 0, h = 2 * k / a, mid, mn_time = 0;
            ll res = 0;
            // while (l <= h)
            // {
            //     mid = l + (h - l) / 2;
            //     if (mid * mid == (2 * k) / a)
            //     {
            //         mn_time = mid;
            //         break;
            //     }
            //     if (mid * mid < 2 * k / a)
            //     {
            //         l = mid + 1;
            //         mn_time = mid;
            //     }
            //     else
            //         h = mid - 1;
            // }
            // mn_time = min(mn_time, m);

            l = 0, h = m;
            while (l <= h)
            {
                mid = l + (h - l) / 2;
                if ((mid * mid + mid) * a >= (2 * k))
                {
                    res = mid;
                    h = mid - 1;
                }
                else
                    l = mid + 1;
            }

            cout << res << "\n";
        }
    }

    return 0;
}