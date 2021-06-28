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
    TreeNode* trimBST(TreeNode* root, int low, int high) {

        function<void(TreeNode*)> deleteTree = [&](TreeNode* root) {
            if (!root) return;
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        };

        function<TreeNode*(TreeNode*)> trimBST = [&](TreeNode* root) {
            if (!root) return (TreeNode*)nullptr;
            if (root->val < low) {
                TreeNode* res = trimBST(root->right);
                // deleteTree(root->left);
                // delete root;
                return res;
            }
            if (root->val > high) {
                TreeNode* res = trimBST(root->left);
                // deleteTree(root->right);
                // delete root;
                return res;
            }
            root->left = trimBST(root->left);
            root->right = trimBST(root->right);
            return root;
        };
        
        return trimBST(root);
    }
};