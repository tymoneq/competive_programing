#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;

vector<int> adj[N];
int Sto[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Sto[b]++;
        adj[a].push_back(b);
    }

    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (Sto[i] == 0)
        {
            ans.push_back(i);
            q.push(i);
        }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w : adj[v])
        {
            Sto[w]--;
            if (Sto[w] == 0)
            {
                q.push(w);
                ans.push_back(w);
            }
        }
    }

    if (ans.size() == n)
        for (int w : ans)
            cout << w << " ";

    else
        cout << "IMPOSSIBLE";
    cout << "\n";
    return 0;
}