#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        vector<int> p(n);
        vector<bool> used(n, false);    // used[i]：nums[i]使用过
        vector<vector<int>> res;
        dfs(nums, 0, p, used, res);
        return res;
    }

private:
    void dfs(const vector<int>& nums, 
        int i, vector<int>& p, vector<bool>& used, vector<vector<int>>& res) {
        // 已经生成序列p，将要在位置i放置数字

        if (i == nums.size()) {
            res.emplace_back(p);
            return;
        }

        for (int j = 0; j < nums.size(); j++) {
            if (!used[j]) {
                p[i] = nums[j];
                used[j] = true;
                dfs(nums, i + 1, p, used, res);
                used[j] = false;
            }
        }
    }
};