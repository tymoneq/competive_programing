#include <bits/stdc++.h>

using namespace std;

vector<int> Colors[6];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, q, x, y, res, tmp;
    string s;
    map<string, int> Legend = {{"BG", 0}, {"BR", 1}, {"BY", 2}, {"GR", 3}, {"GY", 4}, {"RY", 5}};
    vector<pair<string, string>> V;
    cin >> t;

    while (t--)
    {
        cin >> n >> q;
        V.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            Colors[Legend[s]].push_back(i);
            V[i].first = s[0];
            V[i].second = s[1];
        }

        for (int i = 0; i < 6; i++)
            sort(Colors[i].begin(), Colors[i].end());

        for (int i = 0; i < q; i++)
        {
            cin >> x >> y;
            res = numeric_limits<int>::max();
            if (V[x].first == V[y].first || V[x].first == V[y].second || V[x].second == V[y].first || V[x].second == V[y].second)
                res = abs(x - y);
            else
            {
                set<string> S;

                for (int k = 0; k < 2; k++)
                {
                    if (k == 0)
                        s = V[x].first;
                    else
                        s = V[x].second;

                    for (int j = 0; j < 2; j++)
                    {
                        if (j == 0)
                            s.append(V[y].first);
                        else
                            s.append(V[y].second);

                        S.insert(s);
                        s.erase(1);
                    }
                }

                for (string a : S)
                {
                    if (a[0] > a[1])
                        swap(a[0], a[1]);
                    tmp = Legend[a];
                    auto it = upper_bound(Colors[tmp].begin(), Colors[tmp].end(), x);
                    if (it != Colors[tmp].end())
                        res = min(res, abs(x - *it) + abs(y - *it));
                    if (it != Colors[tmp].begin())
                    {
                        it--;
                        res = min(res, abs(x - *it) + abs(y - *it));
                    }
                }
            }
            if (res == numeric_limits<int>::max())
                res = -1;
            cout << res << "\n";
        }

        for (int i = 0; i < 6; i++)
            Colors[i].clear();
        V.clear();
    }

    return 0;
}