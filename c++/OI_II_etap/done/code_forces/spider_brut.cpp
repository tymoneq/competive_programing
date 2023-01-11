#include <bits/stdc++.h>

using namespace std;
const int M = 3e5 + 10;
vector<int> Graph[M];
int Dist[M], Path[M], Legs[M];
bool Visit[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, pocz, kon, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> Legs[i];
    cin >> pocz >> kon;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (gcd(Legs[i], Legs[j]) != 1)
            {
                Graph[i].push_back(j);
                Graph[j].push_back(i);
            }
        
    if (pocz == kon)
    {
        cout << 1 << "\n"
             << pocz;
        return 0;
    }
    Dist[pocz] = 1;
    queue<int> q;
    q.push(pocz);
    Visit[pocz] = 1;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int w : Graph[v])
            if (!Visit[w])
            {
                Dist[w] = Dist[v] + 1;
                Path[w] = v;
                Visit[w] = 1;
                q.push(w);
            }
    }
    vector<int> p;
    if (Dist[kon] != 0)
    {
        cout << Dist[kon] << "\n";
        while (Path[kon] != 0)
        {
            p.push_back(kon);
            kon = Path[kon];
        }
        p.push_back(pocz);
        for (int i = p.size() - 1; i >= 0; i--)
            cout << p[i] << " ";
    }
    else
    {
        cout << -1;
    }
    return 0;
}