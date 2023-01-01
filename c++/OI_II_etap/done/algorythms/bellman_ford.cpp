#include <bits/stdc++.h>
using namespace std;
const int M = 20;
long long d[M];
struct edge
{
    int a, b, c;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    vector<edge> G;
    edge tmp;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        tmp.a = a, tmp.b = b, tmp.c = c;
        G.push_back(tmp);
    }
    for (int i = 0; i < M; i++)
        d[i] = numeric_limits<int>::max();
    d[0] = 0; // to find negativ cycle repeat loop for one more time
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            if (d[G[j].b] > d[G[j].a] + G[j].c)
                d[G[j].b] = d[G[j].a] + G[j].c;

    for (int i = 0; i <= n; i++)
        cout << d[i] << " ";
    return 0;
}