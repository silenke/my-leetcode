#include "..\..\leetcode.h"

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int res = 0;
        int l = 0, r = 0;
        int count = 0;
        while (r < nums.size()) {
            count += nums[r++] & 1;
            if (count != k) continue;
            int right = 0;
            while (r < nums.size() && !(nums[r] & 1)) {
                right++;
                r++;
            }
            int left = 0;
            while (!(nums[l] & 1)) {
                left++;
                l++;
            }
            res += (left + 1) * (right + 1);
            l++;
            count--;
        }
        return res;
    }
};