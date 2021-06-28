#include "..\..\leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        queue<pair<TreeNode*, TreeNode*>> q;
        if (root) q.emplace(root->left, root->right);
        while (!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            if (!a && !b) continue;
            if (!a || !b) return false;
            if (a->val != b->val) return false;
            q.emplace(a->left, b->right);
            q.emplace(a->right, b->left);
        }
        return true;
    }
};