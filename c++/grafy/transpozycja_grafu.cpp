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
    }
    vector<int> G_transpoz[n];
    for (int i = 0; i < n; i++)
    {
        if (!G[i].empty())
        {
            for (auto el : G[i])
            {
                G_transpoz[el].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        for (auto el : G_transpoz[i])
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}
