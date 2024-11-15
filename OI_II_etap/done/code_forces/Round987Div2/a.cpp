#include <bits/stdc++.h>

using namespace std;

inline void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> Cnt;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        Cnt[a]++;
    }

    int mx = 0;
    for (auto el : Cnt)
        mx = max(el.second, mx);

    cout << n - mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}