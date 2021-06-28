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
    void flatten(TreeNode* root) {

        dfs(root);
    }

private:
    TreeNode* dfs(TreeNode* root) {

        if (!root) return nullptr;
        
        TreeNode* lh = root->left;
        TreeNode* rh = root->right;

        TreeNode* lt = dfs(root->left);
        TreeNode* rt = dfs(root->right);

        root->left = nullptr;
        TreeNode* right = root;
        if (lh) {
            right->right = lh;
            right = lt;
        }
        if (rh) {
            right->right = rh;
            right = rt;
        }
        return right;
    }
};