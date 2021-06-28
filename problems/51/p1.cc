#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        u = vector<bool>(n, false);
        u1 = u2 = vector<bool>(n * 2 - 1, false);

        res.clear();
        vector<int> c(n);
        dfs(n, 0, c);
        return res;
    }

private:
    vector<bool> u, u1, u2;
    vector<vector<string>> res;

    void dfs(int n, int i, vector<int>& c) {
        // c[i]：i行放置皇后的列，将要在i行放置皇后

        if (i == n) {
            generate(c);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!u[j] && !u1[i + j] && !u2[i - j + n - 1]) {
                c[i] = j;
                u[j] = u1[i + j] = u2[i - j + n - 1] = true;
                dfs(n, i + 1, c);
                u[j] = u1[i + j] = u2[i - j + n - 1] = false;
            }
        }
    }

    void generate(vector<int>& c) {

        int n = c.size();

        vector<string> tmp(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            tmp[i][c[i]] = 'Q';
        }
        res.emplace_back(tmp);
    }
};