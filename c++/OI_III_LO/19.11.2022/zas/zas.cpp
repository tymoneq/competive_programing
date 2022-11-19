#include <bits/stdc++.h>
using namespace std;
bool sorto(pair<int, int> lhs, pair<int, int> rhs)
{
    if (lhs.first < rhs.first)
        return true;
    if (lhs.first == rhs.first)
        if (lhs.second < rhs.second)
            return true;

    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int D, x1, y1, x2, y2, n, res = 0;
    cin >> D >> x1 >> y1 >> x2 >> y2 >> n;
    vector<pair<int, int>> Towers(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        Towers[i] = make_pair(a, b);
    }
    sort(Towers.begin(), Towers.end(), sorto);
    for (int i = 0; i < n - 1; i++)
    {
        if (Towers[i + 1].first - D > Towers[i].first)
        {
            //if (Towers[i + 1].second - D > Towers[i].second)
                res += 1;
        }
        else if (Towers[i + 1].second - D > Towers[i].second)
            //if (Towers[i + 1].first - D > Towers[i].first)
                res += 1;
    }
    cout << res;
    return 0;
}