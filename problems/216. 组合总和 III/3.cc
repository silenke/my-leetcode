#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> res;
        vector<int> c;
        function<void(int, int)> dfs = [&](int n, int i) {
            if (n == 0 && c.size() == k) {
                res.emplace_back(c);
                return;
            }
            if (n == 0 || c.size() == k) return;
            int m = 10 - (k - c.size());
            for (int j = i; j <= m; j++) {
                if (j > n) break;
                c.emplace_back(j);
                dfs(n - j, j + 1);
                c.pop_back();
            }
        };
        dfs(n, 1);
        return res;
    }
};