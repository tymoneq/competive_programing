#include <bits/stdc++.h>
using namespace std;
int Graph[8][8];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, v, x;
    cin >> n >> m;
    if (n <= 6)
    {
        cout << m;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a][b] = 1, Graph[b][a] = 1;
    }
    int mini = 1e5;
    for (int i = 1; i < 8; i++)
        for (int j = 1; j < 8; j++)
        {
            x = 0;
            for (int k = 1; k < 8; k++)
                if (Graph[i][k] && Graph[k][j])
                    x++;
            mini = min(mini, x);
        }
    cout << m - mini;
    return 0;
}