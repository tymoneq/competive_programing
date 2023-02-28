#include <bits/stdc++.h>
using namespace std;
constexpr int M = 1e5 + 10;
vector<int> Tree[M];

int dfs(int v, int p)
{
    int cows = Tree[v].size();
    int days = 0;
    int c = 1, res = 0;
    if (p == -1)
        cows++;
    while (c < cows)
    {
        days++;
        c *= 2;
    }
    res += days;

    for (int w : Tree[v])
        if (w != p)
            res += dfs(w, v) + 1;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    cout << dfs(1, -1);

    return 0;
}