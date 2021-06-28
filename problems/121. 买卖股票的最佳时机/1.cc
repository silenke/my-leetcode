#include "..\..\leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int res = 0;
        int min_p = INT_MAX;
        for (int p : prices) {
            res = max(res, p - min_p);
            min_p = min(min_p, p);
        }
        return res;
    }
};