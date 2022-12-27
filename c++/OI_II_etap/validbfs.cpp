#include <bits/stdc++.h>

using namespace std;
const int MAX_val = 2e5 + 10;
vector<int> T[MAX_val];
vector<int> Tree[MAX_val];
bool Visited[MAX_val];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, v;
    cin >> n;
    vector<int> To_check(n + 1);

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        T[b].push_back(a);
        T[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        cin >> To_check[i];
    queue<int> Q;
    Q.push(1);
    Visited[1] = 1;
    while (!Q.empty())
    {
        v = Q.front();
        Q.pop();
        for (int w : T[v])
            if (!Visited[w])
            {
                Tree[v].push_back(w);
                Q.push(w);
                Visited[w] = 1;
            }
    }

    if (To_check[1] != 1)
    {
        cout << "No";
        return 0;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(Tree[1].size(), 1));
    bool findd = false;
    for (int i = 2; i <= n; i++)
    {
        auto v = q.front();
        q.pop();
        for (int j = 0; j < v.first; j++)
        {
            findd = 0;
            for (int k = 0; k < v.first; k++)
                if (To_check[i + j] == Tree[v.second][k])
                {
                    findd = 1;
                    q.push(make_pair(Tree[To_check[i + j]].size(), To_check[i + j]));
                    break;
                }
            if (!findd)
            {
                cout << "No";
                return 0;
            }
        }
        i += v.first - 1;
    }
    cout << "Yes";
    return 0;
}