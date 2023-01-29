#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> Films(n);
    for (int i = 0; i < n; i++)
        cin >> Films[i].second >> Films[i].first;
    sort(Films.begin(), Films.end());
    int max_Movies = 0;
    multiset<int> Members;
    for (int i = 0; i < k; i++)
        Members.insert(0);

    for (int i = 0; i < n; i++)
    {
        auto it = Members.upper_bound(Films[i].second);
        if (it == begin(Members))
            continue;
        Members.erase(--it);
        Members.insert(Films[i].first);
        max_Movies++;
    }
    cout << max_Movies;
    return 0;
}