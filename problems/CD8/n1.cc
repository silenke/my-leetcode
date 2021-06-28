#include "..\..\leetcode.h"

class Solution {
public:
    int maxLength(vector<int>& nums, int k) {
        
        int l = 0;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum > k) {
                sum -= nums[l++];
            }
            if (sum == k) {
                res = max(res, i - l + 1);
            }
        }
        return res;
    }
};