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

        return dfs(root, LONG_MIN, LONG_MAX);
    }

private:
    bool dfs(TreeNode* root, long long l, long long r) {

        if (root == nullptr) return true;

        return l < root->val && root->val < r &&
            dfs(root->left, l, root->val) && dfs(root->right, root->val, r); 
    }
};