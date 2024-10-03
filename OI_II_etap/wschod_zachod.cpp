#include <bits/stdc++.h>

using namespace std;

// #warning change N = 1e6+10;
constexpr int N = 1e6 + 10;
int d[N];
bool Vis[N], Off[N];
vector<int> adj[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w, z, a, b, p;
    cin >> n >> w >> z;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    vector<int> V;
    cin >> p;
    int ans = 0;
    for (int i = 0; i < p; i++)
    {
        cin >> a;
        V.push_back(a);
    }
    for (int city : V)
    {
        int tmp_min = numeric_limits<int>::max(), City;
        q.push(city);
        d[city] = 0;
        Vis[city] = 1;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int w : adj[v])
                if (!Vis[w])
                {
                    d[w] = d[v] + 1;
                    Vis[w] = 1;
                    q.push(w);
                }
        }

        for (int i = n; i >= n - z + 1; i--)
            if (!Off[i] && d[i] < tmp_min)
            {
                City = i;
                tmp_min = d[i];
            }

        ans = max(ans, tmp_min);
        Off[City] = 1;
        for (int i = 1; i <= n; i++)
            Vis[i] = 0, d[i] = 0;
    }
    cout << ans << "\n";
    return 0;
}
