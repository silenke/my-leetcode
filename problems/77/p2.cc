#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;
        vector<int> c(k);
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i == k) {
                res.emplace_back(c);
                return;
            }
            if (k - i > n - j + 1) return;
            c[i] = j;
            dfs(i + 1, j + 1);
            dfs(i, j + 1);
        };
        dfs(0, 1);
        return res;
    }
};