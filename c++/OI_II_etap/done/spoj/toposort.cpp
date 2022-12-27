#include <bits/stdc++.h>
using namespace std;
const int MAX_val = 10010;
vector<int> G[MAX_val];
int STO[MAX_val];
bool Vis[MAX_val];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, v;
    vector<int> res;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
        STO[b] += 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (Vis[i])
            continue;
        if (STO[i] == 0)
        {
            Vis[i] = 1;
            q.push(i);
            res.push_back(i);
            while (!q.empty())
            {
                v = q.front();
                q.pop();
                for (int w : G[v])
                {
                    STO[w]--;
                    Vis[w] = 1;
                    if (STO[w] == 0)
                    {
                        q.push(w);
                        res.push_back(w);
                    }
                }
            }
        }
    }

    if (res.size() == n)
        for (int el : res)
            cout << el << " ";
    else
        cout << "Sandro fails.";
    return 0;
}