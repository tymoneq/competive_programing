#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
public:
    inline int binarySearch(const int &val, const vector<int> &Prices)
    {
        int lo = 0, hi = Prices.size() - 1, mid, ans = -1;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Prices[mid] <= val)
            {
                lo = mid + 1;
                ans = mid;
            }
            else
                hi = mid - 1;
        }

        return ans;
    }

    inline void solve()
    {
        int N, Q;
        vector<int> Prices;
        cin >> N;
        Prices.resize(N);
        FOR(i, N, 0)
        cin >> Prices[i];

        sort(Prices.begin(), Prices.end());

        cin >> Q;
        while (Q--)
        {
            int m;
            cin >> m;

            int ans = binarySearch(m, Prices);
            cout << ans + 1 << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve s;
    s.solve();

    return 0;
}