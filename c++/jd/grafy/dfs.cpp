#include <bits/stdc++.h>

using namespace std;

void dfs(int a, bool *visted, vector<vector<int>> &G)
{
    visted[a] = true;
    cout << a << "\n";
    for (auto el : G[a])
    {
        if (!visted[el])
        {
            dfs(el, visted, G);
        }
    }
}

int main()
{
    int wierz, kra;
    cin >> wierz >> kra;
    vector<vector<int>> G(wierz);
    bool visted[wierz]{0};
    for (int i = 0; i < kra; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, visted, G);
    for (auto el : visted)
    {

        cout << el << " ";
    }
    return 0;
}