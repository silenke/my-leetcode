#include "..\..\leetcode.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int n = nums.size();

        vector<int> sums(n + 1);    // sums[i]：前i个元素的前缀和
        sums[0] = 0;
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {   // 以位置i开始的最小子数组
            auto it = lower_bound(sums.begin() + i + 1, sums.end(), sums[i] + s);
            if (it != sums.end()) {
                res = min(res, static_cast<int>(it - sums.begin()) - i);
            }
            else break;
        }
        return res < INT_MAX ? res : 0;
    }
};