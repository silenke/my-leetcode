#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {

        vector<int> res;
        int i = A.size() - 1;
        while (i >= 0 || K > 0) {
            int n = K % 10 + (i >= 0 ? A[i--] : 0);
            res.emplace_back(n % 10);
            K = K / 10 + n / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};