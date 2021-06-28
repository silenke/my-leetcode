#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        if (nums.empty()) return {};

        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, int i, vector<vector<int>>& res) {
        // nums：已经得到的排列，i：要处理的位置
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            dfs(nums, i + 1, res);
            swap(nums[i], nums[j]);
        }
    }
};