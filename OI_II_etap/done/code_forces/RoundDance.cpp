#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        vector<set<int>> g(n);
        vector<set<int>> neighbours(n);
        vector<int> d(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
            g[i].insert(a[i]);
            g[a[i]].insert(i);
        }

        for (int i = 0; i < n; i++)
            d[i] = g[i].size();

        int bamboos = 0, cycles = 0;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                vector<int> components = {i};
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for (int v : g[u])
                        if (!vis[v])
                        {
                            q.push(v);
                            components.push_back(v);
                            vis[v] = 1;
                        }
                }

                bool bamboo = 0;
                for (int j : components)
                    if (d[j] == 1)
                    {
                        bamboo = 1;
                        break;
                    }
                if (bamboo)
                    bamboos++;
                else
                    cycles++;
            }
        }

        cout << cycles + min(1, bamboos) << " " << cycles + bamboos << "\n";
    }

    return 0;
}