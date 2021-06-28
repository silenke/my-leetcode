#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param n: the value from 1 - n
     * @param value: the value of coins
     * @param amount: the number of coins
     * @return: how many different value
     */
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
        // write your code here
        vector<bool> dp(n + 1);
        // dp[j]：前i个物品可以装满容量为j的背包
        dp[0] = true;
        int res = 0;
        for (int i = 0; i < value.size(); i++) {
            vector<int> count(n + 1);
            for (int j = value[i]; j <= n; j++) {
                if (!dp[j] && dp[j - value[i]] && count[j - value[i]] < amount[i]) {
                    count[j] = count[j - value[i]] + 1;
                    dp[j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};