#include <bits/stdc++.h>

using namespace std;
constexpr int M = 300010;
vector<int> Tree[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, v, tmp, p;
    cin >> n;
    int mx = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    mx = Tree[1].size();
    queue<pair<int, int>> q;
    for (int w : Tree[1])
        q.push({w, 1});
    while (!q.empty())
    {
        v = q.front().first;
        p = q.front().second;
        q.pop();
        tmp = Tree[v].size() - 1;
        mx = max(mx, tmp);
        for (int w : Tree[v])
            if (w != p)
                q.push({w, v});
    }
    cout << mx;
    return 0;
}