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

            if (i - k >= dq.front()) dq.pop_front();

            if (i - k + 1 >= 0) res.emplace_back(nums[dq.front()]);
        }
        return res;
    }
};