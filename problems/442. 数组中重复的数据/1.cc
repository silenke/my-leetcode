#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> res;
        for (int n : nums) {
            int k = n < 0 ? -n : n;
            if (nums[k - 1] < 0) res.push_back(k);
            else nums[k - 1] = -nums[k - 1];
        }
        return res;
    }
};