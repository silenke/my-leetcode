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
    int kthSmallest(TreeNode* root, int k) {

        int res = -1;
        while (root) {
            TreeNode* left = root->left;
            if (left) {
                while (left->right && left->right != root) {
                    left = left->right;
                }
                if (!left->right) {
                    left->right = root;
                    root = root->left;
                    continue;
                }
                left->right = nullptr;
            }
            if (k-- == 1) res = root->val;
            root = root->right;
        }
        return res;
    }
};