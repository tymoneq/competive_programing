#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;
typedef long long ll;

ll D[N];
vector<pair<int, ll>> adj[N];
int Parent[N];
bool Vis[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    ll c;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 1; i <= n; i++)
        D[i] = numeric_limits<ll>::max();

    pq.push({0, 1});
    D[1] = 0;
    Parent[1] = 1;
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        if (!Vis[v.second])
        {
            for (auto w : adj[v.second])
                if (D[w.first] > D[v.second] + w.second)
                {
                    Parent[w.first] = v.second;
                    D[w.first] = D[v.second] + w.second;
                    pq.push({D[w.first], w.first});
                }

            Vis[v.second] = 1;
        }
    }

    if (D[n] == numeric_limits<ll>::max())
        cout << "NIE\n";
    else
    {
        if (n == 1)
            cout << 0 << "\n1\n";
        else
        {
            vector<int> ans;
            int p = Parent[n];
            ans.push_back(n);
            while (Parent[p] != p)
            {
                ans.push_back(p);
                p = Parent[p];
            }
            ans.push_back(1);
            cout << ans.size() - 1 << "\n";

            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}