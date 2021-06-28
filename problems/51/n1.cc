#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        res.clear();
        u = vector<bool>(n, false);
        u1 = vector<bool>(n * 2 - 1, false);
        u2 = vector<bool>(n * 2 - 1, false);
        vector<int> r(n);
        dfs(n, 0, r);
        return res;
    }

private:
    vector<vector<string>> res;
    vector<bool> u, u1, u2;

    void dfs(int n, int i, vector<int>& r)
    {   // i：要处理的行，r：已经处理的行（每行的皇后在哪列）
        if (i == n) {
            generate(r);
            return;
        }

        for (int j = 0; j < n; j++) {   // 遍历每列
            if (!u[j] && !u1[i + j] && !u2[i - j + n]) {
                r[i] = j;
                u[j] = u1[i + j] = u2[i - j + n] = true;
                dfs(n, i + 1, r);
                u[j] = u1[i + j] = u2[i - j + n] = false;
            }
        }
    }

    void generate(vector<int>& r) {
        int n = r.size();
        vector<string> tmp(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            tmp[i][r[i]] = 'Q';
        }
        res.emplace_back(tmp);
    }
};