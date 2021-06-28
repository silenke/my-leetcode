#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> c;
        function<void(int)> dfs = [&](int i) {
            res.emplace_back(c);
            for (int j = i; j < n; j++) {
                if (j > i && nums[j] == nums[j - 1]) continue;
                c.emplace_back(nums[j]);
                dfs(j + 1);
                c.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};