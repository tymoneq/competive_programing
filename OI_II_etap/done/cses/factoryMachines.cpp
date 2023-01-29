#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> Machine;

inline bool valid(long long v)
{
    unsigned long long complete = 0;
    for (int i = 0; i < n; i++)
    {
        complete += v / Machine[i];
        if (complete >= k)
            return 1;
    }
    return complete >= k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    Machine.resize(n);
    for (int i = 0; i < n; i++)
        cin >> Machine[i];

    sort(Machine.begin(), Machine.end());
    unsigned long long lo = 0, hi = Machine[n - 1] * k, mid, res = hi;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (valid(mid))
            hi = mid - 1, res = min(res, mid);
        else
            lo = mid + 1;
    }
    cout << res;
    return 0;
}