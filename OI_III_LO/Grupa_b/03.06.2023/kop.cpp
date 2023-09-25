#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> Gold;
inline bool sortGold(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (rhs.first == lhs.first)
        return lhs.second < rhs.second;
    return lhs.first < rhs.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s, w, n, x, y;
    cin >> s >> w >> n;
    Gold.resize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> Gold[i].first >> Gold[i].second;
    sort(Gold.begin(), Gold.end(), sortGold);
    int res = 0;
    
    cout << res;
    return 0;
}
