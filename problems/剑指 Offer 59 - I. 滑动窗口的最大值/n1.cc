#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if (nums.empty()) return {};

        const int n = nums.size();
        vector<int> res(n - k + 1);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while(!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.emplace_back(nums[i]);
            int l = i - k + 1;
            if (l >= 0) {
                res[l] = dq.front();
                if (nums[l] == dq.front()) dq.pop_front();
            }
        }
        return res;
    }
};