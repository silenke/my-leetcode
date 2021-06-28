#include "..\..\leetcode.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int res = INT_MAX;
        sort(coins.rbegin(), coins.rend());
        function<void(int, int, int)> dfs = [&](int amount, int count, int i) {
            // 目标金额amount，已经使用硬币数count，要使用硬币i
            if (amount == 0) {
                res = min(res, count);
                return;
            }
            if (i == coins.size()) return;
            for (int j = amount / coins[i]; j >= 0 && count + j < res; j--) {
                dfs(amount - j * coins[i], count + j, i + 1);
            }
        };
        dfs(amount, 0, 0);
        return res == INT_MAX ? -1 : res;
    }
};