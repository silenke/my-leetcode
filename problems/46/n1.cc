#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        if (nums.empty()) return {};

        res.clear(); used.clear();
        vector<int> p(nums.size());
        dfs(nums, 0, p);
        return res;
    }

private:
    vector<vector<int>> res;
    unordered_map<int, bool> used;

    void dfs(const vector<int>& nums, int i, vector<int>& p)
    {   // i：要处理的数字，p：已经生成的数组
        if (i == nums.size())
        {
            res.emplace_back(p);
            return;
        }
        for (int n : nums)
        {
            if (!used[n])
            {
                p[i] = n;
                used[n] = true;
                dfs(nums, i + 1, p);
                used[n] = false;
            }
        }
    }
};