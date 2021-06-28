#include "..\..\leetcode.h"

class Solution {
public:
    int uniquePaths(int m, int n) {

        long res = 1;
        for (int i = 1, j = n; i < m; i++, j++) {
            res = res * j / i;
        }
        return res;
    }
};