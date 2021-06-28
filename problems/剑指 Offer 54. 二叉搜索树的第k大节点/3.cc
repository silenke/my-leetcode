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
    int kthLargest(TreeNode* root, int k) {

        int res;
        while (root) {
            TreeNode* right = root->right;
            if (right) {
                while (right->left && right->left != root) {
                    right = right->left;
                }
                if (right->left == nullptr) {
                    right->left = root;
                    root = root->right;
                    continue;
                }
                right->left = nullptr;
            }
            if (--k == 0) res = root->val;
            root = root->left;
        }
        return res;
    }
};