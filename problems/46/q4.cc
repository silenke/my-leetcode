#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        const int n = nums.size();
        vector<vector<int>> res;
        vector<int> p(n);
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                res.emplace_back(p);
                return;
            }
            for (int& j : nums) {
                if (j == INT_MAX) continue;
                p[i] = j;
                j = INT_MAX;
                dfs(i + 1);
                j = p[i];
            }
        };
        dfs(0);
        return res;
    }
};