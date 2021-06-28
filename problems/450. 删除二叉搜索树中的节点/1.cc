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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == nullptr) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->left == nullptr) {
                TreeNode* right = root->right;
                delete root;
                root = right;
            }
            else if (root->right == nullptr) {
                TreeNode* left = root->left;
                delete root;
                root = left;
            }
            else {
                TreeNode* next = root->right;
                while (next->left) {
                    next = next->left;
                }
                root->val = next->val;
                root->right = deleteNode(root->right, next->val);
            }
        }
        return root;
    }
};