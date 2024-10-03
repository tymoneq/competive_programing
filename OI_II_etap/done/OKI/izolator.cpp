#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll res = 0;
    vector<int> Warstwa(n);
    for (int &a : Warstwa)
    {
        cin >> a;
        res += a;
    }

    sort(Warstwa.begin(), Warstwa.end());
    int l = 0, r = n - 1;

    while (l < r)
    {
        res += Warstwa[r] - Warstwa[l];
        l++, r--;
    }

    cout << res << "\n";

    return 0;
}