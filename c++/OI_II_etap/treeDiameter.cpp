#include <bits/stdc++.h>
using namespace std;
constexpr int M = 10;
vector<int> Tree[M];
int Pre[M], Post[M];
bool Vis[M];
int timer;
inline void dfs(int v)
{
    Vis[v] = 1;
    timer++;
    Pre[v] = timer;
    for (int w : Tree[v])
        if (!Vis[w])
            dfs(w);
    Post[v] = timer;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--, b--;
        Tree[a].push_back(b), Tree[b].push_back(a);
    }
    dfs(0);
    int centroid = 0;
    bool fint = 1;
    for (int i = 0; i < n; i++)
    {
        fint = 1;
        for (int w : Tree[i])
            if (Post[w] - Pre[w] > n / 2)
            {
                fint = 1;
                break;
            }
        if (fint)
        {
            centroid = i;
            break;
        }
    }

    return 0;
}