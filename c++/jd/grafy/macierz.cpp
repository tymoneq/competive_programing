#include <bits/stdc++.h>

using namespace std;

int main()
{

    int node;
    cin >> node;
    int edge;
    cin >> edge;
    int G[node + 1][node + 1];
    

    for (int i = 0; i <= node; i++)
    {
        for (int j = 0; j <= node; j++)
            G[i][j] = 0;
            
    }
    int a, b;
    for (int i = 0; i < edge; i++)
    {

        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    for (int i = 0; i <= node; i++)
    {
        for (int j = 0; j <= node; j++)
            cout << G[i][j] << " ";

        cout << endl;
    }

    return 0;
}