#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, x, m, res;
    cin >> n;
    vector<int> Prices(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> Prices[i];

    cin >> q;
    sort(Prices.begin(), Prices.end());
    for (int i = 0; i < q; i++)
    {
        cin >> m;
        auto itr = lower_bound(Prices.begin(), Prices.end(), m);
        res = itr - Prices.begin();
        
        if (*itr != m)
            res--;
        cout << res << "\n";
    }
    return 0;
}