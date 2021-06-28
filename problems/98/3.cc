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

        long pre = LONG_MIN;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                s.emplace(root);
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();
                if (pre >= root->val) return false;
                pre = root->val;
                root = root->right;
            }
        }
        return true;
    }
};