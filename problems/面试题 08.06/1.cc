#include "..\..\leetcode.h"

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {

        hanota(A.size(), A, B, C);
    }

private:
    void hanota(int n, vector<int>& from, vector<int>& help, vector<int>& to) {

        if (n > 1) hanota(n - 1, from, to, help);
        to.emplace_back(from.back()); from.pop_back();
        if (n > 1) hanota(n - 1, help, from, to);
    }
};