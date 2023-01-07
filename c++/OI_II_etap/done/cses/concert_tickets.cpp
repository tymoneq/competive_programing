#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, h, x;
    cin >> n >> m;
    multiset<int> Prize;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Prize.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> h;
        auto it = Prize.upper_bound(h);
        if (it == Prize.begin())
            cout << -1 << "\n";
        else
        {
            cout << *(--it) << "\n";
            Prize.erase(it);
        }
    }
    return 0;
}