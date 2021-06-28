#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {

        const int n = a.size();
        vector<int> res(n, 1);
        int l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            res[i] *= l;
            res[n - 1 - i] *= r;
            l *= a[i];
            r *= a[n - 1 - i];
        }
        return res;
    }
};