#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<bool> used(n, false);
        vector<int> p(n);
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                res.emplace_back(p);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (used[j]) continue;
                if (j > 0 && nums[j] == nums[j - 1] && !used[j - 1]) continue;
                p[i] = nums[j];
                used[j] = true;
                dfs(i + 1);
                used[j] = false;
            }
        };
        dfs(0);
        return res;
    }
};