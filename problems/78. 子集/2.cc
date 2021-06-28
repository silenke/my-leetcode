#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> c;
        function<void(int)> dfs = [&](int i) {
            if (i == nums.size()) {
                res.emplace_back(c);
                return;
            }
            c.push_back(nums[i]);
            dfs(i + 1);
            c.pop_back();
            dfs(i + 1);
        };
        dfs(0);
        return res;
    }
};