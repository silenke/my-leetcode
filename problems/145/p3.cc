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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;

        stack<TreeNode*> s1, s2;
        if (root) s1.emplace(root);
        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.emplace(node);
            if (node->left) s1.emplace(node->left);
            if (node->right) s1.emplace(node->right);
        }
        while (!s2.empty()) {
            res.emplace_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }
};