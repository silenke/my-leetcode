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
    bool isValidBST(TreeNode* root) {

        return dfs(root, nullptr, nullptr);
    }

private:
    bool dfs(TreeNode* root, TreeNode* left, TreeNode* right) {

        if (root == nullptr) return true;

        if (left && left->val >= root->val) return false;
        if (right && right->val <= root->val) return false;
        return dfs(root->left, left, root) && dfs(root->right, root, right);
    }
};