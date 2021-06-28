#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        const int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < (1 << n); i++) {
            vector<int> c;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    c.push_back(nums[j]);
                }
            }
            res.emplace_back(c);
        }
        return res;
    }
};