#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < (1 << n); i++) {
            vector<int> c;
            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (j > 0 && nums[j] == nums[j - 1] && !(i & (1 << (j - 1)))) {
                        valid = false;
                        break;
                    }
                    c.emplace_back(nums[j]);
                }
            }
            if (valid) res.emplace_back(c);
        }
        return res;
    }
};