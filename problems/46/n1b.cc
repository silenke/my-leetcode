#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        if (nums.empty()) return {};

        res.clear();
        used = vector<bool>(nums.size(), false);
        vector<int> p(nums.size());
        dfs(nums, 0, p);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> used;

    void dfs(const vector<int>& nums, int i, vector<int>& p) {
        
        if (i == nums.size()) {
            res.emplace_back(p);
            return;
        }

        for (int j = 0; j < nums.size(); j++) {
            if (!used[j]) {
                p[i] = nums[j];
                used[j] = true;
                dfs(nums, i + 1, p);
                used[j] = false;
            }
        }
    }
};