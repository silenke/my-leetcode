#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {

        vector<int> res;
        int i = A.size() - 1;
        while (i >= 0 || K > 0) {
            if (i >= 0) K += A[i--];
            res.emplace_back(K % 10);
            K /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};