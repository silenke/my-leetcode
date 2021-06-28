#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param n: Your money
     * @param prices: Cost of each university application
     * @param probability: Probability of getting the University's offer
     * @return: the  highest probability
     */
    double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
        // write your code here
        for (double& p : probability) {
            p = 1 - p;
        }
        vector<double> dp(n + 1, 1);
        // dp[j]：前i个学校使用j费用的全部失败的最小概率
        for (int i = 0; i < prices.size(); i++) {
            for (int j = n; j >= prices[i]; j--) {
                dp[j] = min(dp[j], dp[j - prices[i]] * probability[i]);
            }
        }
        return 1 - dp[n];
    }
};//':
>>:
