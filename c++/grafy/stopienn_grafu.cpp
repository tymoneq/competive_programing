#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> G[n];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int dg = 0;
    for (int i = 0; i < n; i++)
    {
        int dv = 0;
        for (auto el : G[i])
        {
            // if (i == el)
            //     dv += 2;
            // else
            dv += 1;
        }
        if (dv > dg)
            dg = dv;
    }
    cout << dg << "\n";
    return 0;
}