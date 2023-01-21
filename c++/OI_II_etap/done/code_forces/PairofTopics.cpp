#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> Topic(n);
    for (int i = 0; i < n; i++)
        cin >> Topic[i].first;
    for (int i = 0; i < n; i++)
        cin >> Topic[i].second;
    vector<int> C(n);
    for (int i = 0; i < n; i++)
        C[i] = Topic[i].first - Topic[i].second;

    sort(C.begin(), C.end());
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        if (C[i] <= 0)
            continue;
        int pos = lower_bound(C.begin(), C.end(), -C[i] + 1) - C.begin();
        res += i - pos;
    }

    cout << res;
    return 0;
}