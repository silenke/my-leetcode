#include "..\..\leetcode.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        function<int(int)> dfs = [&](int target) {
            if (dp[target] == -1) {
                int res = 0;
                for (int n : nums) {
                    if (target >= n) {
                        res += dfs(target - n);
                    }
                }
                dp[target] = res;
            }
            return dp[target];
        };
        return dfs(target);
    }
};