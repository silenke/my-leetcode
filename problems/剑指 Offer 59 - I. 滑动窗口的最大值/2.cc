#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.emplace_back(i);
            int l = i - k + 1;
            if (l >= 0) {
                res.emplace_back(nums[dq.front()]);
                if (l == dq.front()) dq.pop_front();
            }
        }
        return res;
    }
};