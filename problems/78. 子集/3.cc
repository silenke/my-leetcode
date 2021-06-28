#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        const int n = nums.size();
        vector<vector<int>> res;
        vector<int> c;
        function<void(int)> dfs = [&](int i) {
            res.emplace_back(c);
            for (int j = i; j < n; j++) {
                c.emplace_back(nums[j]);
                dfs(j + 1);
                c.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};