#include "..\..\leetcode.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        const int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(),
            [](vector<int>& a, vector<int>& b){ return a[0] < b[0]; });
        vector<int> dp(n);  // dp[i]：以信封i为最外层的LIC长度
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            res = max(res, ++dp[i]);
        }
        return res;
    }
};