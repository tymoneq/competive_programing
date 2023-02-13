#include <bits/stdc++.h>
using namespace std;
constexpr int M = 2.5e5 + 10;
int Depth[M], Roads[M], R[M];
vector<int> Tree[M];
void dfs(int v, int p, int d)
{
    Depth[v] = d;
    R[v] = p;
    for (int w : Tree[v])
        if (w != p)
            dfs(w, v, d + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    char oper;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    dfs(1, 1, 0);
    cin >> m;
    int sum, tmp;
    for (int i = 1; i < m + n; i++)
    {
        cin >> oper;
        if (oper == 'W')
        {
            cin >> a;
            sum = Depth[a] - Roads[a];
            tmp = R[a];
            while (tmp != 1)
            {
                sum -= Roads[tmp];
                tmp = R[tmp];
            }
            cout << sum << "\n";
        }
        else
        {
            cin >> a >> b;
            Roads[max(a, b)]++;
        }
    }
    return 0;
}