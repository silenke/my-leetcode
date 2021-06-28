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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;

        queue<pair<TreeNode*, string>> q;
        if (root) q.emplace(root, "");
        while (!q.empty()) {

            auto [node, s] = q.front();
            q.pop();

            s += to_string(node->val);
            if (!node->left && !node->right) {
                res.emplace_back(s);
                continue;
            }
            
            s += "->";
            if (node->left) q.emplace(node->left, s);
            if (node->right) q.emplace(node->right, s);
        }
        return res;
    }
};