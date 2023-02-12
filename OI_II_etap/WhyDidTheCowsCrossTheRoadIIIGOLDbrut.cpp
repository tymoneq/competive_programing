#include <bits/stdc++.h>

using namespace std;
int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    vector<pair<int, int>> Cows(n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a;
        if (Cows[a].first == 0)
            Cows[a].first = i;
        else
            Cows[a].second = i;
    }
    long long res = 0;
    sort(Cows.begin(), Cows.end());
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (Cows[i].first < Cows[j].first && Cows[i].second < Cows[j].second && Cows[i].second > Cows[j].first)
                res++;
    cout << res;
    return 0;
}