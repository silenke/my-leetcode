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
    vector<int> levelOrder(TreeNode* root) {

        vector<int> res;
        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            root = q.front(); q.pop();
            res.emplace_back(root->val);
            if (root->left) q.emplace(root->left);
            if (root->right) q.emplace(root->right);
        }
        return res;
    }
};