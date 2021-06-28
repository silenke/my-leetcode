#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, int i, vector<vector<int>>& res) {
        // 已经生成序列nums[0,i)，将要在位置i放置数字

        if (i == nums.size()) {
            res.emplace_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            dfs(nums, i + 1, res);
            swap(nums[i], nums[j]);
        }
    }
};