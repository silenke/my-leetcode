#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> res;
        for (int i = 0; i < (1 << 9); i++) {
            vector<int> c;
            int sum = 0;
            for (int j = 1; j <= 9; j++) {
                if (10 - j < k - c.size()) break;
                if (i & (1 << (j - 1))) {
                    c.push_back(j);
                    sum += j;
                    if (sum > n) break;
                }
            }
            if (c.size() == k && sum == n) {
                res.emplace_back(c);
            }
        }
        return res;
    }
};