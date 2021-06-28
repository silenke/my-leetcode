#include "..\..\leetcode.h"

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {

        function<bool(int, int)> dfs = [&](int l, int r) {
            if (l >= r) return true;
            int i = l;
            while (postorder[i] < postorder[r]) i++;
            int j = i;
            while (postorder[j] > postorder[r]) j++;
            return j == r && dfs(l, i - 1) && dfs(i, r - 1);
        };
        return dfs(0, postorder.size() - 1);
    }
};