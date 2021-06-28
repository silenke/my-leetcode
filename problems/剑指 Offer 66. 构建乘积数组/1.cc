#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {

        const int n = a.size();
        if (n == 0) return {};

        vector<int> b(n, 0);
        b[0] = 1;
        for (int i = 1; i < n; i++) {
            b[i] = b[i - 1] * a[i - 1];
        }
        int last = 1;
        for (int i = n - 2; i >= 0; i--) {
            last *= a[i + 1];
            b[i] *= last;
        }
        return b;
    }
};