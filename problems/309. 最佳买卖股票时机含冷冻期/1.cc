#include "..\..\leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int rest = 0;
        int buy = INT_MIN;
        int sell = 0;
        for (int i = 0; i < prices.size(); i++) {
            int last_rest = rest;
            rest = max(rest, sell);
            buy = max(buy, last_rest - prices[i]);  // 不能使用rest，因为上一行包含了冷冻期
            sell = buy + prices[i];
        }
        return max(rest, sell);
    }
};