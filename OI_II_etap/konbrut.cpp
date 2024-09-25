#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e6 + 10;
int Sajz[M];
int zbior1 = 1, zbior2 = 1;
vector<int> Graph[5500];
map<int, pair<vector<int>, int>> Map;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Graph[1].push_back(2);
    Graph[2].push_back(1);
    int q, cur = 2, a;
    char oper;
    cin >> q;
    if (q <= 5000)
        for (int i = 0; i < q; i++)
        {
            cin >> oper >> a;
            if (oper == '?')
                cout << Graph[a].size() << "\n";
            else if (oper == 'Z')
            {
                cur++;
                for (auto w : Graph[a])
                    Graph[w].push_back(cur), Graph[cur].push_back(w);
            }
            else if (oper == 'W')
            {
                cur++;
                Graph[a].push_back(cur);
                Graph[cur].push_back(a);
            }
        }
    else
    {
    }

    return 0;
}