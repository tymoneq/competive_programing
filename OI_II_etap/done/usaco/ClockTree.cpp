#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2510;
int Clocks[M];
vector<int> Tree[M];
int sum0, sum1, nodes0, nodes1;
void dfs(int v, int p, int color)
{
    if (color == 0)
    {
        nodes0++;
        sum0 += Clocks[v];
    }
    else
    {
        nodes1++;
        sum1 += Clocks[v];
    }
    for (int w : Tree[v])
        if (w != p)
            dfs(w, v, 1 - color);
}
int main()
{
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Clocks[i];
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        a--, b--;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    dfs(0, 0, 0);
    if ((sum0 % 12) == (sum1 % 12))
        cout << n;
    else if ((sum0 + 1) % 12 == (sum1 % 12))
        cout << nodes1;
    else if ((sum0 % 12) == (sum1 + 1) % 12)
        cout << nodes0;
    else
        cout << 0;
    return 0;
}