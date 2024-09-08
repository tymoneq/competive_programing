#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;

vector<int> Tree[N];
bool HasCat[N];
int CatEncountered[N];
int res = 0, m;

void dfs(int v, int p)
{
    if (HasCat[v])
        CatEncountered[v] = CatEncountered[p] + 1;
    if (CatEncountered[v] > m)
        return;

    if (Tree[v].size() == 1 && v != 1)
        ++res;

    for (int w : Tree[v])
        if (w != p)
            dfs(w, v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> HasCat[i];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    dfs(1, 0);

    cout << res << "\n";

    return 0;
}