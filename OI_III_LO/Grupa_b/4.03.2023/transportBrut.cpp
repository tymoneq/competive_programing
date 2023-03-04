#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (lhs.first == rhs.first)
        return lhs.second < rhs.second;
    return lhs.first < rhs.first;
}
constexpr int M = 3e5 + 10;
bool used[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> Biz(n); // first masa second val
    for (int i = 0; i < n; i++)
        cin >> Biz[i].first >> Biz[i].second;
    sort(Biz.begin(), Biz.end(), sorto);
    vector<int> Bags(k);
    for (int i = 0; i < k; i++)
        cin >> Bags[i];
    sort(Bags.begin(), Bags.end());
    ull res = 0;
    int mx, ind;
    for (int bag : Bags)
    {
        mx = 0;
        ind = -1;
        for (int i = 0; i < n; i++)
        {
            if (Biz[i].first <= bag && !used[i] && mx < Biz[i].second)
            {
                mx = Biz[i].second;
                ind = i;
            }
        }
        res += mx;
        if (ind != -1)
            used[ind] = 1;
    }
    cout << res;
    return 0;
}