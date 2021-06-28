#include "..\..\leetcode.h"

class Solution {
public:
    int totalNQueens(int n) {

        int res = 0;
        function<void(int, int, int, int)> dfs = [&](int i, int col, int pie, int na) {
            // 将要在i行放置皇后，列col，副对角线pie，主对角线na
            if (i == n) {
                res++;
                return;
            }
            int bits = ~(col | pie | na) & ((1 << n) - 1);
            while (bits) {
                int j = bits & -bits;
                dfs(i + 1, (col | j), (pie | j) << 1, (na | j) >> 1);
                bits &= (bits - 1);
            }
        };
        dfs(0, 0, 0, 0);
        return res;
    }
};