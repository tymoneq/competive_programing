#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> Days(n);
    for (int i = 0; i < n; i++)
        cin >> Days[i].first >> Days[i].second;
    sort(Days.begin(), Days.end());
    long long res = 0, current_time = 0;

    for (int i = 0; i < n; i++)
    {
        current_time += Days[i].first;
        res += Days[i].second - current_time;
    }
    cout << res;
    return 0;
}