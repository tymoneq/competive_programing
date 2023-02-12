#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e6 + 10;
int Zbior[M];
int zbior1 = 1, zbior2 = 1;
vector<int> Graph[5500];
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
        Zbior[1] = 1, Zbior[2] = 2;
        for (int i = 0; i < q; i++)
        {
            cin >> oper >> a;
            if (oper == '?')
            {
                if (Zbior[a] == 1)
                    cout << zbior2 << "\n";
                else
                    cout << zbior1 << "\n";
            }
            else if (oper == 'Z')
            {
                cur++;
                if (Zbior[a] == 2)
                {
                    Zbior[cur] = 2;
                    zbior2++;
                }
                else
                {
                    Zbior[cur] = 1;
                    zbior1++;
                }
            }
        }
    }
    return 0;
}