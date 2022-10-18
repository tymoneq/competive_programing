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
    // dfs(0, visted, G);

    stack<int> S;
    S.push(0);
    visted[0] = true;
    while (!S.empty())
    {
        int a = S.top();
        S.pop();

        for (auto el : G[a])
        {
            if (!visted[el])
            {
                S.push(el);
                visted[el] = true;
            }
        }
    }
    for (auto el : visted)
    {
        cout << el << " ";
    }

    return 0;
}