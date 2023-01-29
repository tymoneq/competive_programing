#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 1e5 * 2 + 10;

int RES[MAX_VAL];
bool Visited[MAX_VAL];
vector<int> Graph[MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, a, aktual_res = 0, v;
    vector<int> nodes;
    queue<int> Q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            Graph[j].push_back(a);
        }
        for (int j = 1; j <= n; j++)
        {
            if (Graph[j].size() == 0)
            {
                Visited[j] = 1;
                RES[j] = 1;
            }
            else if (!Visited[j])
            {
                aktual_res = 1;
                Visited[j] = 1;
                Q.push(j);
                nodes.clear();
                while (!Q.empty())
                {
                    v = Q.front();
                    Q.pop();
                    for (int b : Graph[v])
                    {
                        if (Visited[b])
                            break;
                        nodes.push_back(b);
                        aktual_res++;
                        Q.push(b);
                    }
                }
                RES[j] = aktual_res;
                for (auto el : nodes)
                {
                    RES[el] = aktual_res;
                    Visited[el] = 1;
                }
            }
        }
        for (int j = 1; j <= n; j++)
        {
            cout << RES[j] << " ";
            RES[j] = 0;
            Visited[j] = 0;
            Graph[j].clear();
        }
        cout << "\n";
    }

    return 0;
}