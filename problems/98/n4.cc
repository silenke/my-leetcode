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

        bool res = true;
        long long prev = LONG_MIN;
        while (root) {
            TreeNode* left = root->left;
            if (left) {
                while (left->right && left->right != root) {
                    left = left->right;
                }
                if (left->right == nullptr) {
                    left->right = root;
                    root = root->left;
                    continue;
                }
                left->right = nullptr;
            }
            if (prev >= root->val) res = false;
            prev = root->val;
            root = root->right;
        }
        return res;
    }
};