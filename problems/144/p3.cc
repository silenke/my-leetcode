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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;

        stack<TreeNode*> s;
        if (root) s.emplace(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            res.emplace_back(node->val);
            if (node->right) s.emplace(node->right);
            if (node->left) s.emplace(node->left);
        }
        return res;
    }
};