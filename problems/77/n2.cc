#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;
        vector<int> c(k + 1);
        iota(c.begin(), c.end(), 1);
        c.back() = n + 1;

        int i = 0;
        while (i < k) {
            res.emplace_back(c.begin(), c.begin() + k);
            i = 0;
            while (i < k && c[i] + 1 == c[i + 1]) {
                c[i] = i + 1;
                i++;
            }
            c[i]++;
        }
        return res;
    }
};