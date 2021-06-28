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

        while (root) {
            TreeNode* head = root->left;
            if (head) {
                TreeNode* tail = head;
                while (tail->right) {
                    tail = tail->right;
                }
                tail->right = root->right;
                root->left = nullptr;
                root->right = head;
            }
            root = root->right;
        }
    }
};