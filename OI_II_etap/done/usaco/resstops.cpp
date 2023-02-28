#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs) { return lhs.second > rhs.second; }
int main()
{
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l, n, RF, RB;
    cin >> l >> n >> RF >> RB;
    vector<pair<int, int>> Grass(n);
    for (int i = 0; i < n; i++)
        cin >> Grass[i].first >> Grass[i].second;
    sort(Grass.begin(), Grass.end(), sorto);
    ull res = 0, posF = 0, posB = 0, timerB = 0, tmp;
    for (int i = 0; i < n; i++)
        if (posB < Grass[i].first)
        {
            timerB = (Grass[i].first - posB) * RB;
            posB = Grass[i].first;
            tmp = (Grass[i].first - posF) * RF;
            posF = Grass[i].first;
            res += Grass[i].second * (tmp - timerB);
        }

    cout << res;
    return 0;
}