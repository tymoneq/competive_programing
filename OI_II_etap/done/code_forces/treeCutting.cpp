#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;

vector<int> adj[N];
vector<pair<int, int>> L;

void dfs(int v, int p, int d)
{
    for (int w : adj[v])
        if (w != p)
            dfs(w, v, d + 1);

    if (adj[v].size() == 1)
        L.push_back({d, v});
}

bool valid(int lenght, int k, int &n)
{
    vector<int> D(n + 1);
    vector<bool> Vis(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    for (auto w : L)
    {
        pq.push(w);
        D[w.second] = 1;
    }

    while (!pq.empty())
    {
        if (k == 0)
        {
            while (!pq.empty())
            {
                auto v = pq.top();
                Vis[v.second] = 1;
                pq.pop();
                for (int w : adj[v.second])
                    if (!Vis[w])
                    {
                        if (D[w] == 0)
                        {
                            pq.push({v.first - 1, w});
                            D[w]++;
                        }
                        D[w] += D[v.second];
                    }
            }
            if (D[1] >= lenght)
                return 1;
            else
                return 0;
        }
        auto v = pq.top();
        Vis[v.second] = 1;
        pq.pop();
        if (pq.size() == 0)
            break;

        if (D[v.second] >= lenght)
        {
            k--;
            for (int w : adj[v.second])
                if (D[w] == 0)
                {
                    D[w] = 1;
                    pq.push({v.first - 1, w});
                }
        }
        else
            for (int w : adj[v.second])
                if (!Vis[w])
                {
                    if (D[w] == 0)
                    {
                        pq.push({v.first - 1, w});
                        D[w]++;
                    }
                    D[w] += D[v.second];
                }
    }

    if (k == 0)
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 1, 0);
        int lo = 0, hi = n, ans = -1, mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (valid(mid, k, n))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        cout << ans << "\n";

        for (int i = 0; i <= n; i++)
            adj[i].clear();
        L.clear();
    }

    return 0;
}