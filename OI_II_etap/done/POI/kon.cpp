#include <bits/stdc++.h>
using namespace std;
constexpr int M = 1e6 + 10;
int Sajz[M], Rep[M];
map<int, vector<int>> Connections;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Sajz[1] = 1;
    Sajz[2] = 1;
    Rep[1] = 1;
    Rep[2] = 2;

    int x, q, cur = 3;
    char zapytanie;
    Connections[1].push_back(2);
    Connections[2].push_back(1);
    cin >> q;

    while (q--)
    {
        cin >> zapytanie >> x;

        if (zapytanie == '?')
        {
        }
        else if (zapytanie == 'Z')
        {
            Rep[cur] = Rep[x];
            Sajz[Rep[x]]++;
            cur++;
        }
        else
        {
            Rep[cur] = cur;
            Sajz[cur] = 1;
            Connections[cur].push_back(x);
            Connections[x].push_back(cur);
            cur++;
        }
    }

    return 0;
}