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

        long long pre = LONG_MIN;
        return isValidBST(root, pre);
    }

private:
    bool isValidBST(TreeNode* root, long long& pre) {
        
        if (root == nullptr) return true;

        if (!isValidBST(root->left, pre)) return false;

        if (pre >= root->val) return false;

        pre = root->val;

        return isValidBST(root->right, pre);
    }
};