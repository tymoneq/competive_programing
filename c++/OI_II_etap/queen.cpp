#include <bits/stdc++.h>

using namespace std;
const int MAX_val = 1e5 + 10;

pair<int, vector<int>> Tree[MAX_val];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, p;

    cin >> n;
    vector<int> To_delete, res;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> p;
        if (a == -1)
            continue;
        else
        {
            Tree[i].first = a;
            Tree[a].second.push_back(i);
            if (p == 1)
                To_delete.push_back(i);
        }
    }
    sort(To_delete.begin(), To_delete.end());
    int tmp, val = 0;
    if (To_delete.size() == n)
    {
        for (int el : To_delete)
            cout << el << " ";
        return 0;
    }
    for (int i = 0; i < To_delete.size(); i++)
    {
        val = 0;
        for (int v : Tree[To_delete[i]].second)
        {
            auto itr = find(To_delete.begin(), To_delete.end(), v);
            if (itr != To_delete.end())
                val++;
        }
        if (val == Tree[To_delete[i]].second.size())
        {
            res.push_back(To_delete[i]);
            for (int B : Tree[To_delete[i]].second)
            {
                Tree[B].first = Tree[To_delete[i]].first;
                tmp = Tree[To_delete[i]].first;
                Tree[tmp].second.push_back(B);
            }
            Tree[To_delete[i]].first = 0;
            Tree[To_delete[i]].second.clear();
        }
    }
    if (res.size() == 0)
        cout << -1;
    for (int el : res)
        cout << el << " ";
    return 0;
}