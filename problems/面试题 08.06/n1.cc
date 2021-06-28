#include "..\..\leetcode.h"

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {

        dfs(A.size(), A, C, B);
    }

private:
    void dfs(int n, vector<int>& from, vector<int>& to, vector<int>& tmp) {

        if (n > 1) dfs(n - 1, from, tmp, to);
        to.emplace_back(from.back()); from.pop_back();
        if (n > 1) dfs(n - 1, tmp, to, from);
    }
};