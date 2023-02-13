#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    double a, b;
    cin >> n >> q;
    multiset<double> lo, hi;
    for (int i = 1; i <= q; i++)
    {
        cin >> a;
        if (i == 1)
        {
            lo.insert(a);
            cout << fixed << setprecision(1) << a << "\n";
        }
        else
        {
            if (hi.size() > 0 && a > *hi.begin())
            {
                if (hi.size() == lo.size())
                {
                    auto it = hi.begin();
                    lo.insert(*it);
                    hi.erase(it);
                    hi.insert(a);
                }
                else
                    hi.insert(a);
            }
            else
                lo.insert(a);
            if (lo.size() >= hi.size() + 2)
            {
                auto it = lo.end();
                it--;
                hi.insert(*it);
                lo.erase(it);
            }
            if (i % 2 == 0)
            {
                auto it = lo.end();
                it--;
                b = *it + *hi.begin();
                b /= 2;
                cout << fixed << setprecision(1) << b << "\n";
            }
            else
            {
                auto it = lo.end();
                it--;
                cout << fixed << setprecision(1) << *it << "\n";
            }
        }
    }
    return 0;
}