#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    inline bool valid(int val, int h, vector<int> &piles)
    {
        unsigned long long time = 0;
        for (int w : piles)
        {
            if (w % val != 0)
                time++;
            time += w / val;
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int lo = 1, hi = 1e9 + 10, mid, ans = 0;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (valid(mid, h, piles))
            {
                hi = mid - 1;
                ans = mid;
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

    return 0;
}