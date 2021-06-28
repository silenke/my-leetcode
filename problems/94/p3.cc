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

        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (curr || !s.empty()) {
            if (curr) {
                s.emplace(curr);
                curr = curr->left;
            }
            else {
                curr = s.top();
                s.pop();
                res.emplace_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};