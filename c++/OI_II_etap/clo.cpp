#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
vector<int> Graph[M];
int STO[M], Res[M];
bool Vis[M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;

    if (m < n)
    {
        cout << "NIE";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        STO[a]++, STO[b]++;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    vector<int> V;
    for (int i = 1; i <= n; i++)
        if (STO[i] == 1)
            V.push_back(i);

    cout << "TAK\n";
    if (V.size() == 0)
    {
    }
    else
    {
    }
    return 0;
}