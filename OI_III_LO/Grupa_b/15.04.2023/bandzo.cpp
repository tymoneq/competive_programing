#include <bits/stdc++.h>

using namespace std;
inline bool sortpairs(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (lhs.first == rhs.first)
        return lhs.second > rhs.second;
    return lhs.first < rhs.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0;
    cin >> n;
    vector<pair<int, int>> Humans(n + 1);
    vector<pair<int, int>> TIME; // first time second ind + -> start - -> end
    for (int i = 1; i <= n; i++)
    {
        cin >> Humans[i].first >> Humans[i].second;
        if (Humans[i].first != Humans[i].second)
        {
            TIME.push_back({Humans[i].first, i});
            TIME.push_back({Humans[i].second, -i});
        }
    }
    sort(TIME.begin(), TIME.end(), sortpairs);
    int mx = 0, count = 0;
    set<int> IND, MXIND;
    for (int i = 0; i < TIME.size(); i++)
    {
        if (TIME[i].second > 0)
        {
            count++;
            IND.insert(abs(TIME[i].second));
        }
        else if (TIME[i].second < 0)
        {
            count--;
            IND.erase(abs(TIME[i].second));
        }

        if (count > mx)
        {
            mx = count;
            MXIND = IND;
        }
    }
    res = mx;
    TIME.clear();
    for (int i = 1; i <= n; i++)
        if (!MXIND.count(i))
        {
            TIME.push_back({Humans[i].first, i});
            TIME.push_back({Humans[i].second, -i});
        }

    mx = 0, count = 0;
    for (int i = 0; i < TIME.size(); i++)
    {
        if (TIME[i].second > 0)
            count++;
        else if (TIME[i].second < 0)
            count--;

        if (count > mx)
            mx = count;
    }
    res += mx;
    cout << res;
    return 0;
}