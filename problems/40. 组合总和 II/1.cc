#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> c;
        function<void(int, int)> dfs = [&](int i, int target) {
            if (target == 0) {
                res.emplace_back(c);
                return;
            }
            for (int j = i; j < candidates.size(); j++) {
                if (candidates[j] > target) break;
                if (j > i && candidates[j] == candidates[j - 1]) continue;
                c.push_back(candidates[j]);
                dfs(j + 1, target - candidates[j]);
                c.pop_back();
            }
        };
        dfs(0, target);
        return res;
    }
};