#include "..\..\leetcode.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        int res = 0;
        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            root = q.front(); q.pop();
            if (root->left) {
                if (!root->left->left && !root->left->right) {
                    res += root->left->val;
                }
                else q.emplace(root->left);
            }
            if (root->right) q.emplace(root->right);
        }
        return res;
    }
};