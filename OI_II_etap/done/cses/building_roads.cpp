#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 10;
vector<int> Graph[M];
int R[M];

inline int fint(int v) { return R[v] == v ? v : R[v] = fint(R[v]); }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, v;
    vector<pair<int, int>> res;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        R[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (R[i] != i)
            continue;
        q.push(i);
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            for (int w : Graph[v])
                if (R[w] != i)
                {
                    R[w] = i;
                    q.push(w);
                }
        }
    }
    for (int i = 2; i <= n; i++)
        if (fint(R[i]) != fint(R[1]))
        {
            res.push_back(make_pair(i, 1));
            R[i] = 1;
        }
    cout << res.size() << "\n";
    for (auto el : res)
        cout << el.first << " " << el.second << "\n";

    return 0;
}