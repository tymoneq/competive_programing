#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    vector<int> Towers;
    cin >> n;
    int lo, hi, mid;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        lo = 0, hi = Towers.size();
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Towers[mid] > a)
                hi = mid;
            else
                lo = mid + 1;
        }
        if (lo == Towers.size())
            Towers.push_back(a);
        else
            Towers[lo] = a;
    }

    cout << Towers.size();
    return 0;
}