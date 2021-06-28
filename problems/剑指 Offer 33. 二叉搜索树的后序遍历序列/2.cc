#include "..\..\leetcode.h"

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {

        stack<int> s;
        int root = INT_MAX;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            if (postorder[i] > root) return false;
            while (!s.empty() && postorder[i] < s.top()) {
                root = s.top(); s.pop();
            }
            s.emplace(postorder[i]);
        }
        return true;
    }
};