#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    struct milk
    {
        int timer;
        int to;
        int indx;
    };

    map<int, vector<milk>> Milk;
    map<int, int> Cnt;
    vector<ll> res;
    int N;

public:
    inline void read_data()
    {
        cin >> N;
        res.resize(N + 2);

        FOR(i, N, 0)
        {
            int a;
            cin >> a;
            Milk[a].push_back({0, i, i});
            Cnt[a]++;
        }
    }

    inline int binarySearch(int index, int val)
    {
        int lo = 0, hi = Cnt[val] - 1, mid, ans = -1;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (mid >= index)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return ans;
    }
    inline void solve()
    {
        read_data();

       
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve solution;
    solution.solve();
    return 0;
}