#include "..\..\leetcode.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        const int n = prices.size();
        if (k == 0 || n < 2) return 0;

        if (k >= n / 2) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k);
        for (int p : prices) {
            buy[0] = max(buy[0], -p);
            sell[0] = max(sell[0], buy[0] + p);
            for (int j = 1; j < k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - p);
                sell[j] = max(sell[j], buy[j] + p);
            }
        }
        return sell[k - 1];
    }
};