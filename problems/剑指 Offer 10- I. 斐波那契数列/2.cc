#include "..\..\leetcode.h"

class Solution {
public:
    int fib(int n) {

        if (n < 2) return n;

        matrix a{{1, 1}, {1, 0}};
        return pow(a, n - 1)[0][0];
    }

private:
    const int mod = 1e9 + 7;
    typedef vector<vector<long>> matrix;

    matrix mul(matrix& a, matrix& b) {

        matrix c{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
                c[i][j] %= mod;
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