#include "..\..\leetcode.h"

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        vector<int> map(nums.size() + 1, 0);
        // map[i]：有i个奇数的前缀子数组的个数
        map[0] = 1;
        int res = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i] & 1;
            if (count >= k) res += map[count - k];
            map[count]++;
        }
        return res;
    }
};