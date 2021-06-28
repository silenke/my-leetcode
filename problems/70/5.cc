#include "..\..\leetcode.h"

class Solution {
public:
    int climbStairs(int n) {

        matrix a = {{1, 1}, {1, 0}};
        matrix b = pow(a, n);
        return b[0][0];
    }

private:
    typedef vector<vector<long>> matrix;

    matrix mul(matrix& a, matrix& b) {
        matrix c{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j]+ a[i][1] * b[1][j];
            }
        }
        return c;
    }

    matrix pow(matrix& a, int n) {
        matrix b{{1, 0}, {0, 1}};
        while (n) {
            if (n & 1) b = mul(b, a);
            a = mul(a, a);
            n >>= 1;
        }
        return b;
    }
};