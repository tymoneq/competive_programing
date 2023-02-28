#include <bits/stdc++.h>
using namespace std;
constexpr int M = 1e5 + 10;
vector<int> Tree[M];
char Type[M];
int main()
{
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    char t;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> Type[i];

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    int comp_numb = 0;
    vector<int> component(n + 1, -1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (component[i] == -1)
        {
            q.push(i);
            t = Type[i];
            while (!q.empty())
            {
                component[q.front()] = comp_numb;
                for (int w : Tree[q.front()])
                    if (component[w] == -1 && t == Type[w])
                        q.push(w);
                q.pop();
            }
            comp_numb++;
        }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        if (component[a] == component[b])
            cout << (Type[a] == t ? 1 : 0);
        else
            cout << 1;
    }
    return 0;
}