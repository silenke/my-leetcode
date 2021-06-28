#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        const int n = nums.size();
        vector<vector<int>> res;
        function<void(int)> dfs = [&](int i) {
            if (i == n - 1) {
                res.emplace_back(nums);
                return;
            }
            for (int j = i; j < n; j++) {
                bool used = false;
                for (int k = i; k < j; k++) {
                    if (nums[k] == nums[j]) {
                        used = true;
                        break;
                    }
                }
                if (used) continue;
                swap(nums[i], nums[j]);
                dfs(i + 1);
                swap(nums[i], nums[j]);
            }
        };
        dfs(0);
        return res;
    }
};