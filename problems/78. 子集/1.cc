#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> c;
        function<void(int, int)> dfs = [&](int k, int i) {
            if (k == 0) {
                res.emplace_back(c);
                return;
            }
            int m = nums.size() - k;
            for (int j = i; j <= m; j++) {
                c.push_back(nums[j]);
                dfs(k - 1, j + 1);
                c.pop_back();
            }
        };
        for (int i = 0; i <= nums.size(); i++) {
            dfs(i, 0);
        }
        return res;
    }
};