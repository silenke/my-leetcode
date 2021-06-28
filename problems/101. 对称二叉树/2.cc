#include "..\..\leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if (root == nullptr) return true;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace(root->left, root->right);
        while (!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            if (a == nullptr && b == nullptr) continue;
            if (a == nullptr || b == nullptr) return false;
            if (a->val != b->val) return false;
            q.emplace(a->left, b->right);
            q.emplace(a->right, b->left);
        }
        return true;
    }
};