#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> res;
        vector<int> c;
        function<void(int, int, int)> dfs = [&](int k, int n, int i) {
            if (k == 0) {
                if (n == 0) res.emplace_back(c);
                return;
            }
            int m = 10 - k;
            for (int j = i; j <= m; j++) {
                if (j > n) break;
                c.push_back(j);
                dfs(k - 1, n - j, j + 1);
                c.pop_back();
            }
        };
        dfs(k, n, 1);
        return res;
    }
};