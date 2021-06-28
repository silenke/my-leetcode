#include "..\..\leetcode.h"

class Solution {
public:
    int maxNum(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n + 1);  // dp[i]：前i个整数异或和为0的子数组最大数量
        dp[0] = 0;
        unordered_map<int, int> map;    // map[x]：异或和x最后出现的子数组大小
        map[0] = 0;
        int x = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            x ^= nums[i - 1];
            auto it = map.find(x);
            if (it != map.end()) {
                dp[i] = max(dp[i], dp[it->second] + 1);
            }
            map[x] = i;
        }
        return dp[n];
    }
};