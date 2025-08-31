
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, vector<int>> Map;

        vector<int> ans(2);

        for (int i = 0; i < nums.size(); i++)
            Map[nums[i]].emplace_back(i);

        for (int i = 0; i < nums.size(); i++)
        {
            int rest = target - nums[i];

            for (int indx : Map[rest])
                if (indx != i)
                {
                    ans[0] = i;
                    ans[1] = indx;

                    return ans;
                }
                }
        return ans;
    }
};
// @lc code=end
