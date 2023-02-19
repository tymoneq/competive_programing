#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (lhs.first < rhs.first)
        return 1;
    if (lhs.first == rhs.first && lhs.second < rhs.second)
        return 1;
    return 0;
}
inline bool sortoO(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (lhs.second < rhs.second)
        return 1;
    if (lhs.second == rhs.second && lhs.first < rhs.first)
        return 1;
    return 0;
}
vector<pair<int, int>> Cows;
int main()
{
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    Cows.resize(N);
    multiset<int> X, Y, leftX, leftY, rightX, RightY;
    for (int i = 0; i < N; i++)
    {
        cin >> Cows[i].first >> Cows[i].second;
        X.insert(Cows[i].first);
        Y.insert(Cows[i].second);
    }
    sort(Cows.begin(), Cows.end(), sorto);
    ll x1 = *X.begin(), x2 = *X.rbegin(), y1 = *Y.begin(), y2 = *Y.rbegin();
    ll filed = (x2 - x1) * (y2 - y1);
    ll ans = 0, areaL, areaR;
    for (int i = 0; i < 2; i++)
    {
        RightY = Y;
        rightX = X;
        leftX.clear();
        leftY.clear();
        for (int i = 0; i < N; i++)
        {
            areaL = areaR = 0;
            leftX.insert(Cows[i].first);
            leftY.insert(Cows[i].second);
            RightY.erase(RightY.find(Cows[i].second));
            rightX.erase(rightX.find(Cows[i].first));
            x1 = *leftX.begin(), x2 = *leftX.rbegin(), y1 = *leftY.begin(), y2 = *leftY.rbegin();
            areaL = (x2 - x1) * (y2 - y1);
            if (RightY.size() > 0)
            {
                x1 = *rightX.begin(), x2 = *rightX.rbegin(), y1 = *RightY.begin(), y2 = *RightY.rbegin();
                areaR = (x2 - x1) * (y2 - y1);
            }
            ans = max(ans, (filed - areaL - areaR));
        }
        sort(Cows.begin(), Cows.end(), sortoO);
    }
    cout << ans;
    return 0;
}