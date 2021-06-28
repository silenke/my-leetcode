#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<int> c(k);
        vector<vector<int>> res;
        dfs(n, k, 0, 1, c, res);
        return res;
    }

private:
    void dfs(int n, int k, int i, int j, vector<int>& c, vector<vector<int>>&res) {
        // 已经生成序列c，将要在位置i放置[j,n]中的数字

        if (i == k) {
            res.emplace_back(c);
            return;
        }

        int max = n + 1 - k + i;    // [m,n]可用的个数 >= 需要的个数k-i;
        for (int m = j; m <= max; m++) { 
            c[i] = m;
            dfs(n, k, i + 1, m + 1, c, res);
        }
    }
};