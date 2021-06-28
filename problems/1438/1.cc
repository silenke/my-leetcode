#include "..\..\leetcode.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int res = 0;

        deque<int> maxs, mins;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            
            while (!maxs.empty() && nums[maxs.back()] <= nums[r]) {
                maxs.pop_back();
            }
            maxs.emplace_back(r);

            while (!mins.empty() && nums[mins.back()] >= nums[r]) {
                mins.pop_back();
            }
            mins.emplace_back(r);

            while (l <= r && nums[maxs.front()] - nums[mins.front()] > limit) {
                if (l >= maxs.front()) maxs.pop_front();
                if (l >= mins.front()) mins.pop_front();
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};