#include <bits/stdc++.h>
using namespace std;
const int M = 20;
vector<int> Graph[M];
long long d[M][M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    long long c;
    cin >> n >> m;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = numeric_limits<int>::max();
        }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        Graph[a].push_back(b);
        d[a][b] = min(c, d[a][b]);
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);

    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < n; j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }
    return 0;
}