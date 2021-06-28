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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;

        TreeNode* curr = root;
        while (curr) {
            TreeNode* left = curr->left;
            if (left) {
                while (left->right && left->right != curr) {
                    left = left->right;
                }
                if (!left->right) {
                    left->right = curr;
                    curr = curr->left;
                    continue;
                }
                else {
                    left->right = nullptr;
                }
            }
            res.emplace_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};