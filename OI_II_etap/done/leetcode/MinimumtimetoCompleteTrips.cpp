#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool valid(long long time, vector<int> &Bus, unsigned long long totalTrips)
    {
        unsigned long long trips = 0;
        for (int w : Bus)
            trips += time / w;
        return totalTrips <= trips;
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        long long lo = 0, hi = 1e14 + 10, mid, ans = 0;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (valid(mid, time, totalTrips))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> Nums = {10000000};
    long long  res = s.minimumTime(Nums, 10000000);
    cout << res;
}