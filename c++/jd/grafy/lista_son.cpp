#include <bits/stdc++.h>

using namespace std;

int main()
{

    int node;
    cin >> node;
    int edge;
    cin >> edge;
    vector<int> G[node + 1];

    int a, b;
    for (int i = 0; i < edge; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= node; i++)
    {
        cout << i << ": ";
        for (auto el : G[i])
        {
            cout << el << " ";
        }
        cout <<"\n";
    }
    return 0;
}