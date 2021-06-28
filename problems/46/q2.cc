#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        const int n = nums.size();
        vector<vector<int>> res;
        function<void(int)> dfs = [&](int i) {
            if (i == n - 1) {
                res.emplace_back(nums);
                return;
            }
            for (int j = i; j < n; j++) {
                swap(nums[i], nums[j]);
                dfs(i + 1);
                swap(nums[i], nums[j]);
            }
        };
        dfs(0);
        return res;
    }
};