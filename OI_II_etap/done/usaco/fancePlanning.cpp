#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
constexpr int M = 1e5 + 10;
pair<ull, ull> Cords[M];
vector<ull> MooConection[M];
bool Vis[M];
ull mnX, mnY, mxX, mxY;
void dfs(int v)
{
    Vis[v] = 1;
    mnX = min(mnX, Cords[v].first);
    mxX = max(mxX, Cords[v].first);
    mnY = min(mnY, Cords[v].second);
    mxY = max(mxY, Cords[v].second);
    for (int w : MooConection[v])
        if (!Vis[w])
            dfs(w);
}
int main()
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> Cords[i].first >> Cords[i].second;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--, b--;
        MooConection[a].push_back(b);
        MooConection[b].push_back(a);
    }
    long long res = numeric_limits<long long>::max(), tmp;
    for (int i = 0; i < n; i++)
        if (!Vis[i])
        {
            mnX = numeric_limits<ull>::max();
            mnY = mnX;
            mxX = mxY = 0;
            dfs(i);
            tmp = (mxX - mnX) * 2 + (mxY - mnY) * 2;
            res = min(res, tmp);
        }
    cout << res;
    return 0;
}