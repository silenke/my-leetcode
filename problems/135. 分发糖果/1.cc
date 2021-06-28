#include "..\..\leetcode.h"

class Solution {
public:
    int candy(vector<int>& ratings) {

        const int n = ratings.size();
        vector<int> nums(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                nums[i] = nums[i - 1] + 1;
            }
            else {
                nums[i] = 1;
            }
        }

        int res = nums.back();
        int last = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                last++;
            }
            else {
                last = 1;
            }
            res += max(nums[i], last);
        }
        return res;
    }
};