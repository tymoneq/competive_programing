#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
vector<int> adj[M];
int Sajz[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, a, b, i;
    pair<int, int> mx;
    set<int> unvis;
    vector<int> res;
    cin >> t;
    for (int l = 0; l < t; l++)
    {
        cin >> n >> m;
        res.clear();
        for (i = 1; i <= n; i++)
            Sajz[i] = 0, adj[i].clear();
        for (i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            Sajz[a]++, Sajz[b]++;
        }

        mx.first = 0;
        for (i = 1; i <= n; i++)
        {
            if (Sajz[i] > mx.first)
                mx.first = Sajz[i], mx.second = i;
            unvis.insert(i);
        }
        res.push_back(mx.second);
        unvis.erase(mx.second);
        for (int w : adj[mx.second])
            unvis.erase(w);
        while (unvis.size() > 0)
        {
            for (i = 1; i <= n; i++)
                Sajz[i] = 0;
            for (i = 1; i <= n; i++)
                if (binary_search(unvis.begin(), unvis.end(), i))
                    for (int w : adj[i])
                        if (binary_search(unvis.begin(), unvis.end(), w))
                            Sajz[i]++;

            mx.first = 0;
            for (i = 1; i <= n; i++)
                if (Sajz[i] > mx.first)
                    mx.first = Sajz[i], mx.second = i;
            res.push_back(mx.second);
            unvis.erase(mx.second);
            for (int w : adj[mx.second])
                unvis.erase(w);
        }

        cout << res.size() << "\n";
        for (int el : res)
            cout << el << " ";
        cout << "\n";
    }

    return 0;
}