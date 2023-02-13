#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unordered_map<char, vector<int>> MAP;
    string s, s2;
    cin >> s;
    int n, ind;
    cin >> n;
    bool corect = 1;
    for (int i = 0; i < s.size(); i++)
        MAP[s[i]].push_back(i);
    for (int i = 0; i < n; i++)
    {
        cin >> s2;
        corect = 1;
        ind = -1;
        for (int j = 0; j < s2.size(); j++)
        {
            if (!MAP.count(s2[j]))
            {
                corect = 0;
                break;
            }
            else
            {
                auto it = upper_bound(MAP[s2[j]].begin(), MAP[s2[j]].end(), ind);
                if (it == MAP[s2[j]].end())
                {
                    corect = 0;
                    break;
                }
                ind = *it;
            }
        }
        cout << (corect ? "TAK\n" : "NIE\n");
    }
    return 0;
}