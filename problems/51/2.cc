#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> res;
        vector<int> c(n);  // c[i]：i行在c[i]列放置皇后
        function<void(int, int, int, int)> dfs = [&](int i, int col, int pie, int na) {
            // 将要在i行放置皇后，列col，副对角线pie，主对角线na
            if (i == n) {
                vector<string> tmp(n, string(n, '.'));
                for (int i = 0; i < n; i++) {
                    tmp[i][c[i]] = 'Q';
                }
                res.emplace_back(tmp);
                return;
            }
            int bits = ~(col | pie | na) & ((1 << n) - 1);
            while (bits) {
                int j = bits & -bits;
                c[i] = j;
                dfs(i + 1, (col | j), (pie | j) << 1, (na | j) >> 1);
                bits &= (bits - 1);
            }
        };
        dfs(0, 0, 0, 0);
        return res;
    }
};