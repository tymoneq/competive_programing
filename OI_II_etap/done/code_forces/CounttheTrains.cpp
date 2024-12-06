#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

inline void solve()
{
    int n, m, mn = numeric_limits<int>::max();
    cin >> n >> m;
    vector<int> A(n);
    set<int> tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (tmp.empty() || A[i] < mn)
        {
            tmp.insert(i);
            mn = A[i];
        }
    }

    while (m--)
    {
        int x, val;
        cin >> x >> val;
        x--;
        A[x] -= val;
        auto it = tmp.upper_bound(x);

        if (it != tmp.begin())
        {
            it = prev(it);
            if (*it == x || A[*it] > A[x])
                tmp.insert(x);
        }
        else
            tmp.insert(x);

        while (1)
        {
            it = tmp.upper_bound(x);
            if (it != tmp.end() && A[*it] >= A[x])
            {
                tmp.erase(it);
            }
            else
                break;
        }

        cout << (int)tmp.size() << ' ';
    }
    cout << '\n';
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
