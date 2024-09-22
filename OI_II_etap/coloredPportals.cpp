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
                set<string> S = {V[x].first.append(V[y].first), V[x].first.append(V[y].second), V[x].second.append(V[y].first), V[x].second.append(V[y].second)};

                for (string a : S)
                {
                    if (a[0] > a[1])
                        swap(a[0], a[1]);
                    for (int w : Colors[Legend[a]])
                    {
                        tmp = abs(x - w) + abs(w - y);
                        res = min(tmp, res);
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