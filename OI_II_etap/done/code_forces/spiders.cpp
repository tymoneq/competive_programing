#include <bits/stdc++.h>
using namespace std;
const int M = 6e5 + 7, m = 3e5;

vector<int> Graph[M];
int Path[M];
queue<int> q;
vector<int> p;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, pocz, kon, v, a,j,i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        if (a == 1)
            continue;
        Graph[i].push_back(a + m);
        Graph[a + m].push_back(i);
        for (j = 2; j * j <= a; j++)
            if (a % j == 0)
            {
                Graph[i].push_back(j + m);
                Graph[j + m].push_back(i);
                if (a / j != j)
                {
                    Graph[a / j + m].push_back(i);
                    Graph[i].push_back(a / j + m);
                }
            }
    }
    cin >> pocz >> kon;
    if (pocz == kon)
    {
        cout << 1 << "\n"
             << pocz;
        return 0;
    }
    q.push(pocz);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int w : Graph[v])
            if (Path[w]==0 && w!=pocz)
            {
                Path[w] = v;
                q.push(w);
            }
    }

    while (Path[kon] != 0)
    {
        if (kon < m)
            p.push_back(kon);
        kon = Path[kon];
    }
    if (kon == pocz)
        p.push_back(pocz);
    if (p.size() == 0)
    {
        cout << -1 << "\n";
        return 0;
    }
    cout << p.size() << "\n";
    for (i = p.size() - 1; i >= 0; i--)
        cout << p[i] << " ";

    return 0;
}